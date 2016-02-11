#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longgestCommonSequence(string &a, string&b){
	//initialize vector<vector> with 0s.
	vector<vector<int>> table(a.size()+1,vector<int>(b.size()+1,0));

	for (int i = 1; i < a.size() + 1; i++){
		for (int j = 1; j < b.size() + 1; j++){
			if (a[i-1] == b[j-1])
			{
				table[i][j] = table[i - 1][j - 1] + 1;
			}
			else{
				table[i][j] = max(table[i][j - 1], table[i - 1][j]);
			}
		}
	}
	return table[a.size()][b.size()];
}

int main(int argc, char ** argv){
	string A = "ABCDEF";
	string B = "ACBEFO";
	cout << longgestCommonSequence(A,B )<<endl;
	getchar();
}