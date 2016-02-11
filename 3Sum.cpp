/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int> &num){
		vector<vector<int>> result = {};
		vector<int> save(3);
		sort(num.begin(), num.end());
		int numLength = num.size();
		vector<int>::size_type i, j, k;
		if (numLength < 3){
			return{};
		}
		for (i = 0; i < numLength - 2; i++){
			j = i + 1;
			k = numLength - 1;
			while (j < k){
				if (num[i] + num[j] + num[k] < 0){
					do
					{
						j++;
					} while (j < k && num[j] == num[j - 1]);
				}
				else if (num[i] + num[j] + num[k] > 0){
					do
					{
						k--;
					} while (k>j && num[k] == num[k + 1]);
				}
				else{
					save[0] = num[i];
					save[1] = num[j];
					save[2] = num[k];
					result.push_back(save);
					do 
					{
						j++;
					} while (j<k && num[j]==num[j-1]);
					do 
					{
						k--;
					} while (k>j && num[k] == num[k+1]);
				}
			}
			while (num[i+1] == num[i])
			{
				i++;
			}
		}
	return result;
	}
	//vector<vector<int> > threeSum(vector<int> &num) {
	//	vector<vector<int>> results = {};
	//	vector<int> save(3);
	//	bool flag = false;
	//	sort(num.begin(), num.end());
	//	int numLength = num.size();
	//	vector<int>::size_type i, j, k;
	//	if (numLength < 3){
	//		return{};
	//	}
	//	for (i = 0; i < numLength - 2; i++){
	//		j = i + 1;
	//		k = numLength - 1;
	//		while (j < k){
	//			if (num[i] + num[j] + num[k] < 0){
	//				j++;
	//				continue;
	//			}
	//			else if (num[i] + num[j] + num[k] > 0){
	//				k--;
	//				continue;
	//			}
	//			else{
	//				save[0] = num[i];
	//				save[1] = num[j];
	//				save[2] = num[k];
	//				vector<vector<int>>::iterator found;
	//				for (found = results.begin(); found != results.end(); found++){
	//					if (*found == save)
	//					{
	//						//existed
	//						flag = true;
	//						break;
	//					}
	//				}
	//				if (flag == true){
	//					flag = false;
	//				}
	//				else{
	//					results.push_back(save);
	//				}
	//				j++;
	//				k--;
	//			}
	//		}
	//	}
	//	return results;
	//}

	//vector<vector<int> > threeSum(vector<int> &num) {
	//	unordered_map<int, int> hashTable;
	//	unordered_map<int, int>::iterator got;
	//	vector<vector<int>> result = {};
	//	int numLength = num.size();
	//	bool flag = true;
	//	vector<int>::size_type i;

	//	if (numLength < 3)
	//	{
	//		return {};
	//	}
	//	//init the hash table
	//	for (i = 0; i < numLength; i++){
	//		got = hashTable.find(num[i]);
	//		if (got == hashTable.end()){
	//			hashTable.insert({ num[i], 1 });
	//		}
	//		else{
	//			got->second++;
	//		}
	//	}
	//	//start to calculate
	//	unordered_map<int, int>::iterator loopi;
	//	unordered_map<int, int>::iterator loopj;
	//	loopi = hashTable.begin();
	//	while (loopi != hashTable.end()){
	//		for (loopj = loopi; loopj != hashTable.end(); loopj++){
	//			if (loopi == loopj && loopi->second == 1){
	//				continue;
	//			}
	//			int key = 0 - loopi->first - loopj->first;
	//			got = hashTable.find(key);
	//			if (got == hashTable.end()){
	//				continue;
	//			}
	//			if (got == loopi && loopi == loopj && got->second <3){
	//				continue;
	//			}
	//			if (got == loopi && loopj != got){
	//				continue;
	//			}
	//			if (got == loopj && loopi != loopj && loopj->second < 2){
	//				continue;
	//			}
	//			//find it
	//			vector<int> save = saveToVector(loopi->first, loopj->first, got->first);
	//			vector<vector<int>>::iterator gotR;
	//			for (gotR = result.begin(); gotR != result.end(); gotR++){
	//				if (*gotR == save){
	//					flag = false;
	//					break;
	//				}
	//			}
	//			if (flag == false){
	//				flag = true;
	//				continue;
	//			}
	//			result.push_back(save);
	//		}
	//		hashTable.erase(loopi);
	//		loopi = hashTable.begin();
	//	}
	//}
	//vector<int> saveToVector(int a, int b, int c){
	//	vector<int> save;
	//	int tmp;
	//	if (b < a){
	//		tmp = a;
	//		a = b;
	//		b = tmp;
	//	}
	//	if (c < a){
	//		tmp = a;
	//		a = c;
	//		c = tmp;
	//	}
	//	if (c < b){
	//		tmp = c;
	//		c = b;
	//		b = tmp;
	//	}
	//	save.push_back(a);
	//	save.push_back(b);
	//	save.push_back(c);
	//	return save;
	//}
};