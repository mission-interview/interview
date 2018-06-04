#include <iostream>
#include <string>

using namespace std;

/*
 * Cracking the coding interview edition 6
 * Problem 1-6 Implement a method to perform basic string compression.
 * Example string aabcccccaaa should be compressed to a2b1c5a3,
 * however if compressed string is bigger than original string, return original string
 */

string compressStr(string str) {
	//Try doing it in place - the only problem is if compressed string is larger than original it will not work since abc will become a1b1c1
	//Leetcode has another variant where we don't need to append 1, so the problem of being larger will not occur
	//CTCI me new string use hui and then finally comparing the length. 
	int count = 1;
	int j = 0;
	int i = 0;
	for(i = 1; i < str.length(); i++) {
		if(str[i] == str[i-1]) count++;
		else {
			str[j++] = str[i-1];
			str[j++] = (count + '0');
			count = 1;
		}
	}
	str[j++] = str[i-1]; //Ye last wala dalna bahot jaruri h, kyunki tum hamesha i-1 dal rhe ho to last reh hi jayega, nhi to see smart variant
	str[j++] = (count + '0');
	return str.substr(0,j);
}

string compressStrSmartVar(string str) {
	int count = 1;
	int j = 0;
	int i = 0;
	for(i = 1; i <= str.length(); i++) {
		if((i != str.length()) && (str[i] == str[i-1])) count++;
		else {
			str[j++] = str[i-1];
			str[j++] = (count + '0');
			count = 1;
		}
	}
	return str.substr(0,j);
}

string compressStrLeetCodeVariant(string str) {
	//Try doing it in place - the only problem is if compressed string is larger than original it will not work since abc will become a1b1c1
	//Leetcode has another variant where we don't need to append 1, so the problem of being larger will not occur
	int count = 1;
	int j = 0;
	int i = 0;
	for(i = 1; i < str.length(); i++) {
		if(str[i] == str[i-1]) count++;
		else {
			str[j++] = str[i-1];
			if(count > 1) str[j++] = (count + '0');
			count = 1;
		}
	}
	str[j++] = str[i-1]; //Ye last wala dalna bahot jaruri h, kyunki tum hamesha i-1 dal rhe ho to last reh hi jayega
	if(count > 1) str[j++] = (count + '0');
	return str.substr(0,j);
}

int main() {
	cout << "aaabbccccaabbbbcabc" << " " << compressStr("aaabbccccaabbbbcabc") << endl;
	cout << "aaabbccccaabbbbcabc" << " " << compressStrSmartVar("aaabbccccaabbbbcabc") << endl;
	cout << "aaabbccccaabbbbcabccc" << " " << compressStr("aaabbccccaabbbbcabccc") << " " << compressStrLeetCodeVariant("aaabbccccaabbbbcabccc") << endl;
	cout << "aaabbccccaabbbbcabccc" << " " << compressStrSmartVar("aaabbccccaabbbbcabccc") << endl;
	cout << "abc" << " " << compressStr("abc") << endl; //Wrong answer a11
	cout << "abc" << " " << compressStrLeetCodeVariant("abc") << endl;
}
