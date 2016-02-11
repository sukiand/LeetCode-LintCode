#include <iostream>
#include <vector>

using namespace std;

void validIP(string &A, int start, int step, string &IP, vector<string> &result){
	//end
	if (step == 4 && start == A.size()){
		IP.resize(IP.size() - 1);
		result.push_back(IP);
		return;
	}

	//other situation
	if (A.size() - start > (4 - step) * 3 || A.size() - start < (4 - step)) return;

	//shoulian
	int num = 0;
	for (int i = start; i < start + 3; i++){
		num = num * 10 + A[i] - '0';
		if (num <= 255){
			IP += A[i];
			validIP(A, i + 1, step + 1, IP+'.', result);
		}
		if (num == 0) break; // allow single 0;
	}
}

vector<string> validIPaddress(string &A){
	vector<string> result;
	string IP;
	validIP(A, 0, 0, IP, result);
	return result;
}

int main(int argc, char** argv){
	string K = "25525511135";
	vector<string> result = validIPaddress(K);
	/*for (auto i = result.begin(); i < result.end(); i++){
		cout << *i.c_str() << endl;
	}*/
	for (int i=0; i < result.size(); i++){
		cout << result[i].c_str() << endl;
	}
	getchar();
}