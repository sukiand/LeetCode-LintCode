#include <iostream>

using namespace std;

int gcd(int a, int b){
	while (a > 0 && b > 0){
		if (a < b){
			b = b - a;
		}
		else a = a - b;
	}
	return a == 0 ? b : a;
}

int main(int argc, char**argv){
	int a = 10, b = 1;
	int g = gcd(a, b);
	cout << a / g << b / g;
	getchar();
}