#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct myCompare{
	bool operator()(int a, int b){
		string sa = to_string(a);
		string sb = to_string(b);
		return (sa + sb) > (sb + sa);
	}
}m_com;

string largestNumber(vector<int> &num) {
	// write your code here
	sort(num.begin(), num.end(), m_com);
	if (num[0] == 0) return "0";
	string result = {};
	for (int i = 0; i < num.size(); i++){
		result += to_string(num[i]);
	}
	return result;
}

int main(int argc, char** argv){
	vector<int> k = { 10,0,0 };
	cout << largestNumber(k);
	getchar();
}