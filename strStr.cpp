#include <iostream>
#include <cstring>

using namespace std;

char * strStr_gcy(const char * a, const char * b){
	if (!*b) return (char *)a;
	const char *p1;
	const char *p2;
	const char *p1_advaced;
	for (p1_advaced =a,p2 = b; *p2; p2++){
		p1_advaced++;
	}
	for (p1 = a, p2 = b; *p1_advaced; p1_advaced++){
		char * p1_mark = (char *)p1;
		while ( *p1 && *p2 && *p1==*p2)
		{
			p1++;
			p2++;
		}
		if (!*p2) return p1_mark;
		else{
			p1 = p1_mark + 1;
		}
	}
	return nullptr;
}

int main(int argc, char ** argv){
	const char * a = "have a nice day!";
	const char * pattern = "nice";
	cout << strStr_gcy(a, pattern);
	cout << strstr(a, pattern);
	getchar();
}