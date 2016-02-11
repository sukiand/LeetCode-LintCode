#include <iostream>

using namespace std;

int findLastWordLength(const char * s){
	int len;
	bool newword = true;
	while (*s){
		if (*s != ' '){
			if (newword){
				newword = false;
				len = 1;
			}
			else{
				len++;
			}
			s++;
		}
		else{
			newword = true;
			s++;
		}
	}
	return len;
}

int main(int argc, char ** argv){
	cout << findLastWordLength("have a nice day ")<<endl;
	getchar();
}