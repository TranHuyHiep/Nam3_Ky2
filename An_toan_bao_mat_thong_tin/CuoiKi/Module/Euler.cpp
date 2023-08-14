#include <iostream>
#include <cmath>
using namespace std;

int power_modulo(int a, int b, int m) {
    int result = 1;
    a %= m;
    while (b > 0) {
	    if (b & 1) {  
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return result;
}

int main() {
    int a, b, m;
    freopen("input.txt", "r", stdin);
    cin >> a >> b >> m;
    int result = power_modulo(a, b, m);
    cout << a << "^" << b << " = " << result << " (mod " << m << ")" << endl;
    return 0;
}
