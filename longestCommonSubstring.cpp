#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int longestCommonSubstring(string &A, string &B){
	int longest = 0;
	int pk = 0;
	for (auto a = A.begin(); a != A.end(); a++){
		for (auto b = B.begin(); b != B.end(); b++){
			int i;
			for (i = 0; (a+i) != A.end() && (b+i) != B.end(); i++){
				cout << *(a + i) << *(b + i) << endl;
				pk++;
				if (*(a+i) != *(b+i)){
					cout << "old_max:" << longest << endl;
					cout << "now" << i << endl;
					longest = max(longest, i);
					cout << "new" << longest << endl;
					break;
				}
			}
			if ((a + i) == A.end() || (b + i) == B.end())
				longest = max(longest, i);
		}
	}
	return longest;
}

int longestCommonSubstring2(string &A, string &B){
	vector<vector<int>> table(A.size() + 1, vector<int>(B.size() + 1, 0));
	int large = 0;
	for (int i = 1; i < A.size() + 1; i++){
		for (int j = 1; j < B.size() + 1; j++){
			if (A[i - 1] == B[j - 1]){
				table[i][j] = table[i - 1][j - 1] + 1;
				large = max(large, table[i][j]);
			}
			//else{
			//	table[i][j] = 0;
			//}
		}
	}
	return large;
}

void main(){
	string A = "www.ninechapter.com code";
	string B = "www.lintcode.com code";
	cout << "Method 1:"<<longestCommonSubstring(A, B) << endl;
	cout << "Method 2:"<<longestCommonSubstring2(A, B) << endl;
	getchar();
}