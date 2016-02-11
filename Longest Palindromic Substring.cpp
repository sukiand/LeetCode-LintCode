/*	Given a string S, find the longest palindromic substring in S. 
	You may assume that the maximum length of S is 1000,
	and there exists one unique longest palindromic substring.
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>

using namespace std;

class Solution {
public:
	string longestPalindrome_93ms(string s) {
		int i,j;
		int length = 0;
		string k;
		if (s.length() == 1){
			k = s;
		}
		for (i = 0; s[i+1] != '\0'; i++){
			if (s[i] == s[i + 1]){
				for (j = 1; i - j >= 0 && s[i + j + 1] != '\0'; j++){
					if (s[i - j] == s[i + j + 1]){
						continue;
					}
					else {
						break;
					}
				}
				if (j*2 > length){
					length = j*2;
					k = s.substr(i - j + 1, length);
				}
			}
			 if (s[i+2]!= '\0' && s[i] == s[i + 2]){
				for (j = 1; i-j>= 0 && s[i + j + 2] != '\0'; j++){
					if (s[i - j] == s[i + j + 2]){
						continue;
					}
					else{
						break;
					}
				}
				if (j*2+1 > length){
					length = j*2+1;
					k = s.substr(i - j + 1, length);
				}
			}
		}
		return k;
	}
};

int main(int argc, char *argv[]){
	Solution solution;
	cout << solution.longestPalindrome("abcba") << endl;
	_getch();
}