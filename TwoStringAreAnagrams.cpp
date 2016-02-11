#include <iostream>
#include <algorithm>

using namespace std;

bool isAnagram(string s, string t){
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	if (t == s) return true;
	return false;
}

void main(int argc, char ** argv){
	string y1 = "ABCD";
	string y2 = "BCDAA";
	cout << isAnagram(y1, y2)<<endl;
	getchar();
}