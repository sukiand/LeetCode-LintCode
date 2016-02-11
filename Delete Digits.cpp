#include <iostream>
#include <string>

using namespace std;

string DeleteDigits(string A, int k) {
	// wirte your code here
	if (k == 0) return A;
	string result(A.size() - k, '9');
	for (int i = 0; i < A.size(); i++){
		int flag = true;
		for (int j = (A.size() - i) >= result.size() ? 0 : result.size() + i - A.size(); j < result.size(); j++){
			if (flag){
				if (result[j] > A[i]){
					result[j] = A[i];
					flag = false;
				}
			}
			else{
				result[j] = '9';
			}

		}

	}
	while (result[0] == '0' && result.size() > 1){
		result = result.substr(1, result.size() - 1);
	}
	return result;
}

void main(){
	cout << DeleteDigits("9876141516171818818181890001988181700198181778786761256512651653145345143", 55);
	getchar();
}