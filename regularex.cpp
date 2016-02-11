#include <iostream>

using namespace std;

bool ismatch(const char * s, const char * p){
	if (*p == '\0') return *s == '\0';

	if (*(p + 1) != '*'){
		if (*p == *s ||
			(*p != '.' && *s != '\0')){
			return ismatch(s + 1, p + 1);
		}
		else return 0;
	}
	else{
		if (*p == *s || 
			(*p == '.' && *s != '\0')){
			return ismatch(s + 1, p);
		}
		else{
			return ismatch(s, p + 2);
		}
	}
}

int main(int argc, char argv){
	cout << ismatch("aa", "a") << endl;
	cout << ismatch("aa", "aa") << endl;
	cout << ismatch("aaa", "aa") << endl;
	cout << ismatch("aa", "a*") << endl;
	cout << ismatch("aa", ".*") << endl;
	cout << ismatch("ab", ".*") << endl;
	cout << ismatch("aab", "c*a*b") << endl;
	getchar();
}