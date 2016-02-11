#include <iostream>

using namespace std;

string addbinary(string a, string b){
	string result;
	int carry = 0;
	for (auto na = a.rbegin(), nb = b.rbegin();
		na != a.rend() || nb != b.rend();
		na = na == a.rend() ? na : ++na,
		nb = nb == b.rend() ? nb : ++nb){
		const int ia = na == a.rend() ? 0 : *na - '0';
		const int ib = nb == b.rend() ? 0 : *nb - '0';
		const int num = (ia+ib+carry)%2;
		carry = (ia+ib+carry) / 2;
		result.insert(result.begin(), num + '0');
	}
	if (carry != 0) result.insert(result.begin(), carry+'0');
	return result;
}

int main(int argc, char** argv){
	cout << addbinary("11111", "1001").c_str();
	getchar();
}