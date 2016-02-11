#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv){
	const string s = "99999";
	string result = "";  //初始化一个空的字符串
	int carry = 1;

	for (string::const_reverse_iterator i = s.rbegin(); i != s.rend(); ++i){  //定义一个迭代器,针对const_reverse_iterator的
		const int b = *i - '0';
		const int n = (b + carry) % 10;
		carry = (b + carry) / 10;
		result.insert(result.begin(), n+'0');
	}
	if (carry){
		result.insert(result.begin(), carry + '0');
	}
	cout << s.c_str() << endl;
	cout << result.c_str() << endl;
	getchar();
}