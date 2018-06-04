#include <iostream>

using namespace std;

bool checkPermutationSort(string a, string b) {
	if(a.length() != b.length()) return false;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for(int i = 0; i < a.length(); i++) {
		if(a[i] != b[i]) return false;
	}

	return true;
}

bool checkPermutationHash(string a, string b) {
	if(a.length() != b.length()) return false;
	int count[256] = {0};

	for(int i = 0; i < a.length(); i++) {
		int val = a[i];
		count[val]++;
	}

	for(int i = 0; i < b.length(); i++) {
		int val = b[i];
		count[val]--;
		if(count[val] < 0) {
			return false;
 	}
 }
 return true;
}

int main() {
// Test Method 1 - Using sort
    cout << "Method 1 - Using sort" << endl;
    string str1 = "testest";
    string str2 = "estxest";
    if(checkPermutationSort(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
    str1 = "hello";
    str2 = "oellh";
    if(checkPermutationSort(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;

//Test Method 2 - Using character count
    cout << "Method 2 - Using character count" << endl;
    str1 = "testest";
    str2 = "estxest";
    if(checkPermutationHash(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
    str1 = "hello";
    str2 = "oellh";
     if(checkPermutationHash(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
    return 0;
}