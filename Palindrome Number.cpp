/* Determine whether an integer is a palindrome. Do this without extra space.*/
#include <iostream>
#include <conio.h>

using namespace std;

class Solution{
public:
	//expand from the middle or compare from the ends
	//compare from the ends may be easier 

		bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x == 0) return true;
		int div = 1;
		while (x / div >= 10) {
			div *= 10;
		}
		while (x != 0) {
			if ( x / div != x % 10 ) return false;
			x = (x % div) / 10;
			div /= 100;
		}
		return true;
	}

		// a strange method. not very fast.
		bool isPalindrome_141ms(int x, int &y) {
		if (x < 0) return false;
		if (x == 0) return true;
		if (isPalindrome_141ms(x / 10, y) && (x % 10 == y % 10)) {
			y /= 10;
			return true;
			}
			else {
				return false;
			}
		}
		bool isPalindrome_141ms(int x) {
			return isPalindrome_141ms(x, x);
		}

	//easy one, use a reverse function, 121ms
	//it has bugs, reverse one number, it can overflow!!!
	bool isPalindrome_121ms(int x){
		if (x < 0){
			return false;
		}
		else if (0 == x)
		{
			return true;
		}
		else if (x == reverse(x)){
			return true;
		}
		else{
			return false;
		}
	}

	int reverse(int x){
		int y = 0;
		for (; x > 0;){
			y = y * 10 + x % 10;
			x /= 10;
		}
		return y;
	}
};

int main(int argc, char *argv[]){
	bool result;
	Solution test;
	result = test.isPalindrome(3210123);
	cout << "3210123" << " is " << result << endl;
	result = test.isPalindrome(0);
	cout << "0" << " is " << result << endl;
	result = test.isPalindrome(3210321);
	cout << "3210321" << " is " << result << endl;
	result = test.isPalindrome(-8);
	cout << "-8" << " is " << result << endl;
	_getch();

}