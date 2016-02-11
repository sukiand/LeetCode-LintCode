#include <iostream>
#include <vector>

using namespace std;

vector<int> singleNumberIII(vector<int> &A) {
	// write your code here
	if (A.size() == 2) return A;
	int r = 0;
	for (int i = 0; i < A.size(); i++){
		r ^= A[i];
	}
	int mask = 1;
	while ((r&mask) == 0){
		mask = mask << 1;
	}
	int k = 0;
	for (int i = 0; i < A.size(); i++){
		if ((A[i] & mask) != 0){
			k ^= A[i];
		}
	}

	vector<int> result = { k, k^r };
	return result;
}

void main(){
	vector<int> k = { 1, 5, -1, 1, 2, 2, 3, 4, 4, 5, 3, 2147483647, 8, 9, 9, 8 };
	k = singleNumberIII(k);
	for (int i = 0; i < k.size(); i++)
	{
		cout << k[i]<<endl;
	}
	getchar();
}