#include <iostream>
#include <string>

using namespace std;

string binaryRepresentation(string n){
	int a = 0;
	double b = 0.0;
	bool flag = true;
	int bit = 0;
	for (int i = 0; i < n.size(); i++){
		if (n[i] == '.') {
			flag = false;
			continue;
		}
		if (flag){
			a = a * 10 + n[i] - '0';
		}
		else{
			bit++;
			b = b * 10 + n[i] - '0';
		}
	}
	while (bit > 0){
		b = b*0.1;
		bit--;
	}
	string result = {};
	if (a == 0)
		result.push_back('0');
	while (a > 0){
		result.push_back((a % 2 + '0'));
		a = a / 2;
	}
	reverse(result.begin(), result.end());
	if (b == 0.0) return result;
	result.push_back('.');
	while (b > 0.0 && result.size() < 32){
		if (b * 2 >= 1) {
			result.push_back('1');
			b = b * 2 - 1;
		}
		else{
			result.push_back('0');
			b = b * 2;
		}
	}
	if (b > 0) return "ERROR";
	else return result;
}

int main(int argc, char **argv){
	string test = "0.0625";
	cout << binaryRepresentation(test);
	getchar();
}