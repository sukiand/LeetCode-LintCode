#include <iostream>
#include <algorithm>

using namespace std;

int isPalindromeString(string s){
	cout << s.c_str();
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	cout << s.c_str();
	for (auto left = s.begin(), right = prev(s.end()); left < right; left++,right--)
	{
		if (*left != *right) return -1;
	}
	return 1;
}

int main(int argc, int argv){
	string s = "Tsst";
	cout<< isPalindromeString(s);
	getchar();
}