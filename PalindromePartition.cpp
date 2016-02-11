#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string &A, int start, int end){
	/*cout << A.substr(start, end - start + 1).c_str()<<endl;*/
	while (start < end && A[start] == A[end]){
		start++;
		end--;
	}
	return (start >= end);
}

void DFS(string &A, int start, vector<string> &path, vector<vector<string>> &result){
	//end
	if (start == A.size()){
		result.push_back(path);
		return;
	}
	//shoulian
	for (int i = start; i < A.size(); i++){
		if (isPalindrome(A, start, i)){
			path.push_back(A.substr(start, i - start + 1));
			DFS(A, i + 1, path, result);
			// must recover the path here, for other brothers
			path.pop_back();
		}
	}
}

vector<vector<string>> partitionPalindrome(string &A){
	vector<vector<string>> result;
	vector<string> path;
	DFS(A, 0, path, result);
	return result;
}

int main(int argc, char **argv){
	string A = "TESTEET";
	auto result = partitionPalindrome(A);
	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[i].size(); j++){
			cout << result[i][j].c_str() << " ";
		}
		cout << endl;
	}
	getchar();
}