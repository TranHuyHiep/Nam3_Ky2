#include <iostream>
#include <vector>
#include <random>
#include <openssl/sha.h>
#include <openssl/bn.h>
#include <openssl/ec.h>
#include <openssl/evp.h>
#include <openssl/objects.h>
using namespace std;

// Tính giá tr? H(M)
vector<unsigned char> hash_message(string message)
{
    vector<unsigned char> digest(SHA256_DIGEST_LENGTH);
    SHA256((unsigned char*)&message[0], message.length(), &digest[0]);
    return digest;
}

// T?o c?p khóa bí m?t và khóa công khai DSA
void generate_dsa_keypair(BIGNUM* p, BIGNUM* q, BIGNUM* h, BIGNUM* xA, BIGNUM* k, EC_POINT*& yA, EC_GROUP*& group)
{
    group = EC_GROUP_new_by_curve_name(NID_secp256k1);
    EC_GROUP_set_point_conversion_form(group, POINT_CONVERSION_COMPRESSED);
    EC_POINT* G = EC_GROUP_get0_generator(group);
    EC_GROUP_get_order(group, q, NULL);

    BN_CTX* ctx = BN_CTX_new();
    BN_generate_prime_ex(p, 256, 0, NULL, NULL, NULL);
    BN_mod(h, p, q, ctx);
    BN_rand_range(xA, q);
    BN_rand_range(k, q);
    yA = EC_POINT_new(group);
    EC_POINT_mul(group, yA, xA, G, NULL, NULL);
}

// T?o ch? ký s? DSA
vector<BIGNUM*> create_dsa_signature(vector<unsigned char> message_hash, BIGNUM* p, BIGNUM* q, BIGNUM* h, BIGNUM* xA, BIGNUM* k, EC_GROUP*& group)
{
    vector<BIGNUM*> signature(2);
    BN_CTX* ctx = BN_CTX_new();

    // Tính r = (G^k mod p) mod q
    EC_POINT* G = EC_GROUP_get0_generator(group);
    EC_POINT* r_point = EC_POINT_new(group);
    BIGNUM* r = BN_new();
    EC_POINT_mul(group, r_point, k, NULL, NULL, NULL);
    EC_POINT_get_affine_coordinates_GFp(group, r_point, r, NULL, ctx);
    BN_mod(r, r, q, ctx);
    signature[0] = r;

    // Tính s = (k^(-1) * (H(M) + xA * r)) mod q
    BIGNUM* s = BN_new();
    BIGNUM* inv_k = BN_new();
    BIGNUM* temp = BN_new();
    BN_mod_inverse(inv_k, k, q, ctx);
    BN_mul(temp, xA, r, ctx);
    BN_add(temp, temp, message_hash.data(), SHA256_DIGEST_LENGTH);
    BN_mul(s, inv_k, temp, ctx);
    BN_mod(s, s, q, ctx);
    signature[1] = s;

    return signature;
}

// Xác minh ch? ký s? DSA
bool verify_dsa_signature(vector<unsigned char> message_hash, vector<BIGNUM*> signature, EC_POINT* yA, EC_GROUP* group)
{
    bool result = false;
    BN_CTX* ctx = BN_CTX_new();

    BIGNUM* r = signature[0];
    BIGNUM* s = signature[1];
    BIGNUM* w = BN_new();
	BN_mod_inverse(w, s, group->order, ctx);
	
	// Tính u1 = (H(M) * w) mod q và u2 = (r * w) mod q
	BIGNUM* u1 = BN_new();
	BIGNUM* u2 = BN_new();
	BN_mul(u1, message_hash.data(), w, ctx);
	BN_mod(u1, u1, group->order, ctx);
	BN_mul(u2, r, w, ctx);
	BN_mod(u2, u2, group->order, ctx);
	
	// Tính v = ((G^u1 * yA^u2) mod p) mod q
	EC_POINT* G = EC_GROUP_get0_generator(group);
	EC_POINT* v_point = EC_POINT_new(group);
	BIGNUM* v = BN_new();
	EC_POINT_mul(group, v_point, u1, G, u2, ctx);
	EC_POINT_mul(group, v_point, NULL, yA, v_point, ctx);
	EC_POINT_get_affine_coordinates_GFp(group, v_point, v, NULL, ctx);
	BN_mod(v, v, group->order, ctx);
	
	// Xác minh ch? ký s?
	result = (BN_cmp(r, v) == 0);
	
	BN_free(r);
	BN_free(s);
	BN_free(w);
	BN_free(u1);
	BN_free(u2);
	BN_free(v);
	EC_POINT_free(v_point);
	
	return result;
}

int main()
{
	// T?o c?p khóa bí m?t và khóa công khai DSA
	BIGNUM* p = BN_new();
	BIGNUM* q = BN_new();
	BIGNUM* h = BN_new();
	BIGNUM* xA = BN_new();
	BIGNUM* k = BN_new();
	EC_POINT* yA = NULL;
	EC_GROUP* group = NULL;
	generate_dsa_keypair(p, q, h, xA, k, yA, group);
	// T?o ch? ký s? DSA
	string message = "Nhom 5!, xin kinh chao";
	vector<unsigned char> message_hash = hash_message(message);
	vector<BIGNUM*> signature = create_dsa_signature(message_hash, p, q, h, xA, k, group);
	
	// In khóa công khai và ch? ký s?
	cout << "DSA public key: " << endl;
	cout << "yA: " << EC_POINT_point2hex(group, yA, POINT_CONVERSION_COMPRESSED, NULL) << endl;
	cout << "r: " << BN_bn2hex(signature[0]) << endl;
	cout << "s: " << BN_bn2hex(signature[1]) << endl;
	
	// Xác minh ch? ký s? DSA
	bool result = verify_dsa_signature(message_hash, signature, yA, group);
	if (result) {
	    cout << "DSA signature verification succeeded." << endl;
	}
	else {
	    cout << "DSA signature verification failed." << endl;
	}
	
	// Gi?i phóng b? nh?
	BN_free(p);
	BN_free(q);
	BN_free(h);
	BN_free(xA);
	BN_free(k);
	EC_POINT_free(yA);
	EC_GROUP_free(group);
	
	for (auto bn : signature) {
	    BN_free(bn);
	}
	
	return 0;
}

