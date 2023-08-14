#include<bits/stdc++.h>
using namespace std;

string caesar(string input, int k) {
	string answer = "";
	for(int i = 0; i < input.size(); i++) {
		char c;
		// neu la chu hoa
		if('A' <= input[i] && input[i] <= 'Z')  {
			// chuyen thanh so
			c = input[i] - 'A';
			c = (c + k) % 26;
			c += 'A';
		} // neu la chu thuong 
		else if('a' <= input[i] && input[i] <= 'z') {
			c = input[i] - 'a';
			c = (c + k) % 26;
			c += 'a';
		}
		answer += c;
	}
	
	return answer;
}

int main(){
	string input = "YOUREONLYYOUNGON";
	int k = 8;
	cout << "input: " << input << ", k = " << k << endl;
	cout << "output: " << caesar(input, k);
}
