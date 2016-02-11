/*	Given a string, find the length of the longest substring without repeating characters.
	For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
	For "bbbbb" the longest substring is "b", with the length of 1.
*/
/*	Solution: read the string from the beginning, when come to the first pair a,
	Then we just compare the length of first to the right a,
	and the longest substring of the left a to the end.
	just like 
	__________a____________a______..._____
	just compare
	__________a____________ and __________a_______...___(this need to calculate the sub again)
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
public:
	//ascall or unicode
	// here is ascall, use table[256] to store
	int lengthOfLongestSubstring(string s){
		bool Tstore[256] = { false };
		int length_flag = 0;
		int starter = 0;
		int i;
		for (i = 0; s[i] != '\0'; i++){
			if (Tstore[s[i]] == false){
				Tstore[s[i]] = true;
			}
			else{
				length_flag = compare(length_flag, i - starter);
				for (; s[starter] != s[i]; starter++){
					Tstore[s[starter]] = false;
				}
				starter++;
			}
		}
		if (s.length() == 0){
			return 0;
		}
		else {
			length_flag = compare(length_flag, s.length() - starter);
			return length_flag;
		}
	}

	int lengthOfLongestSubstring_own(string s){
		int lengthOfSub = 0;
		int starter = 0;
		int i,j;
		unordered_map<char, int> store;
		unordered_map<char, int>::iterator got;
		for (i = 0; s[i] != '\0'; i++){
			got = store.find(s[i]);
			if (store.empty() || got == store.end()){
				store.insert({ s[i], i });
			}
			else{
				lengthOfSub = compare(lengthOfSub, i - starter );
				for (j = starter, starter = got->second + 1; j <= got->second; j++){
					store.erase(store[j]);
				}
			}
		}
		lengthOfSub = compare(lengthOfSub, s.length() - starter);
		return lengthOfSub;
	}
	int compare(int x, int y){
		if (x > y){
			return x;
		}
		else{
			return y;
		}
	}
};