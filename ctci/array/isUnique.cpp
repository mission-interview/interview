#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm> // for sort() 

using namespace std;

bool isUniqueChars(string s) { //Ask interviewer if it's ascii or unicode for deciding has size of 256 or 128.
	if(s.length() > 128) return false;
	vector<bool> char_set(128);
	for (int i = 0; i < s.length(); i++) {
		int val = s[i];
		if (char_set[val]) {
			return false;
		}
		char_set[val] = true;
	}
	return true;
}

bool isUniqueCharsBitVector(string s) { //Assuming only lowercase a to z chars so 26 which will fit 32 bit int. 
	int bitvec;
	for (int i = 0; i < s.length(); i++) {
		int n = s[i]-'a';
		if(bitvec & (1 << n)) return false;
		bitvec |= 1 << n;
	}
	return true;
}

bool isUniqueChars_noDS(string s) {
	
	sort(s.begin(), s.end()); // O(nlogn) sort from <algorithm>

	bool noRepeat = true;
	for (int i = 0 ; i < s.size() - 1; i++){
		if (s[i] == s[i+1]) {
			noRepeat = false;
			break;
		}
	}
	return noRepeat;	
}

int main() {
	vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
	for (auto word : words) {
		cout << word << ": " << boolalpha << isUniqueChars(word) <<endl;
	}
	cout <<endl << "Using bit" <<endl;
	for (auto word : words) {
		cout << word << ": " << boolalpha << isUniqueCharsBitVector(word) <<endl;
	}
	cout <<endl << "Using no Data Structures" <<endl;
	for (auto word : words) {
		cout << word << ": " << boolalpha << isUniqueChars_noDS(word) <<endl;
	}
	return 0;
}