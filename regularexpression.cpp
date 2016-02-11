/*
	Write a function to find the longest common prefix string amongst an array of strings.
*/
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

using namespace std;


class Solution{
public:
	string longestCommonPrefix(vector<string> &strs){
		if (strs.empty()){
			return "";
		}
		return longestCommonPrefixDivide(strs, 0, strs.size()-1);
	}

	string longestCommonPrefixDivide(vector<string> &strs, vector<string>::size_type low, vector<string>::size_type high){
		if (high == low){
			return strs[high];
		}
		else if (high - low == 1){
			return longestCommonPrefixOfTwoString(strs[high], strs[low]);
		}
		else if (high > low){
			vector<string>::size_type mid = (high + low) / 2;
			string leftStr = longestCommonPrefixDivide(strs, low, mid);
			string rightStr = longestCommonPrefixDivide(strs, mid + 1, high);
			return longestCommonPrefixOfTwoString(leftStr, rightStr);
		}
		else {
			return NULL;
		}
	}

	string longestCommonPrefixOfTwoString(string &s1, string &s2){
		string comPrefix;
		if (s1.length() == 0 || s2.length() == 0){
			return "";
		}
		for (int i = 0; i < s1.length(); i++){
			if (i > s2.length()){
				break;
			}
			if (s1[i] != s2[i]){
				break;
			}
			comPrefix.push_back(s1[i]);
		}
		return comPrefix;
	}
};