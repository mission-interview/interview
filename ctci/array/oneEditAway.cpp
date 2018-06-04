#include <iostream>
#include<string>
#include<cmath>

using namespace std;

/* 
 * Problem: There are three possible edits that can be performed on a string.
 * 1. Insert a char.
 * 2. Delete a char.
 * 3. Replace a char.
 *
 * Given two strings, determine if they are one or 0 edit away.
 *
 * Approach :
 * 1. Case when strings are of some length --> possible edit is replace.
 *    If there are more than one mismatch, return false
 *
 * 2. Case when One string is bigger than another
 *    Smaller string ------------> Bigger String
 *                     insert
 *                     delete
 *    smaller string <-----------  Bigger String
 *
 *    Idea is check if there are more than one mismatch discounting the already
 *    difference in the string. Therefore for first mismatch we do not move the pointer
 *    pointing to smaller string, and then expect it to match from next char of bigger
 *    string.
 */

bool isOneEditReplace(string s1, string s2) {
	int index1 = 0;
	int index2 = 0;
	bool firstDiff = false;

	while(index1 < s1.length() && index2 < s2.length()) {
		if(s1[index1] != s2[index2]) {
			if(firstDiff) return false;
			firstDiff = true;
		}
		index1++; index2++; 
	}
	return true;
}

bool isOneEditInsert(string s1, string s2) { //Can s1 be converted to s2 using one insert
	int index1 = 0;
	int index2 = 0;

	while(index1 < s1.length() && index2 < s2.length()) {
		if(s1[index1] != s2[index2]) {
			if(index1 != index2) return false;
		} else {
			index1++;
		}
		index2++;
	}
	return true;
}

bool isOneEditAway(string s1, string s2) {
	if(s1.length() == s2.length()) {
		return isOneEditReplace(s1, s2);
	}
	if(s1.length()+1 == s2.length()) {
		return isOneEditInsert(s1, s2);
	}
		if(s1.length() == s2.length()+1) {
		return isOneEditInsert(s2, s1);
	}
	return false;
}

bool isOneEditAwayOptimized(string s1, string s2) { //Doing both replace and insert check in one pass
	string a,b;
	a = s1.length() <= s2.length() ? s1 : s2;
	b = s1.length() > s2.length() ? s1 : s2;

	int len1 = s1.length();
	int len2 = s2.length();

	if(abs(len1-len2) > 1) return false;

	int index1 = 0;
	int index2 = 0;
	bool firstDiff = false;

	while(index1 < a.length() && index2 < b.length()) {
		if(a[index1] != b[index2]) {
			if(firstDiff) return false;
			firstDiff = true;

			if(len1 == len2) index1++; //On replace move shorter pointer
		} else {
			index1++; //If matching move shorter pointer
		}
		index2++; //always move the bigger string pointer
	}
	return true;
}

void translate( bool result, const std::string str1, const std::string str2) {
    if (result == true ) {
        std::cout << str1 << " and " << str2 << " are one edit away\n";
    } else {
        std::cout << str1 << " and " << str2 << " are not one edit away\n";
    }
}

int main() {
    translate ( isOneEditAway("pale", "ple"), "pale", "ple" );
    translate ( isOneEditAway("pales", "pale"), "pales", "pale" );
    translate ( isOneEditAway("pale", "pales"), "pale", "pales" );
    translate ( isOneEditAway("pale", "bale"), "pale", "bale" );
    translate ( isOneEditAway("pale", "bake"), "pale", "bake" );

    translate ( isOneEditAwayOptimized("pale", "ple"), "pale", "ple" );
    translate ( isOneEditAwayOptimized("pales", "pale"), "pales", "pale" );
    translate ( isOneEditAwayOptimized("pale", "pales"), "pale", "pales" );
    translate ( isOneEditAwayOptimized("pale", "bale"), "pale", "bale" );
    translate ( isOneEditAwayOptimized("pale", "bake"), "pale", "bake" );
    return 0;
}