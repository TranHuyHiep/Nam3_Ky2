#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

string RailFenceEncryption(string input, int key){
	int len_in = input.length();
	vector<string> v(key, "");
	string output = "";
	bool down = true;
	int row = 0;
	
	for(int i = 0; i < len_in; i++) {
		v[row] += input[i];
		
		if(row == 0) {
			down = true;
		} else if(row == key - 1) {
			down = false;
		}
		
		if(down) {
			row++;
		} else {
			row--;
		}
	}	
	
	for(int i = 0; i < key; i++) {
		output += v[i];
	}
		
	return output;
}


int main()
{
	string input = "Thisisasecretmessage";
	int key = 3;
//	cin >> input;
//	cin >> key;
	cout<<"Input: " << input << endl;
	cout<<"Key: " << key << endl;
	
	input = RailFenceEncryption(input, key);
	cout<<"\nRailFence Encyption: "<<input<<endl;
}


