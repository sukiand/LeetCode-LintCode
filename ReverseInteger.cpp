/*	Reverse digits of an integer.
	Example1: x = 123, return 321
	Example2: x = -123, return -321
*/

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Solution{
public:
	int reverse(int x){
		bool flag = false;
		int rev = 0;
		if (x <= -INT_MAX){
			return 0;
		}
		if (x < 0)
		{
			x = -x;
			flag = true;
		}
		for (; x != 0;){
			if (rev > INT_MAX/10){
				return 0;
			}
			rev = rev * 10 + x % 10;
			x = x / 10;
			printf("%d\n", rev);
		}
		if (rev < 0){
			return 0;
		}
		if (flag == true){
			return (-rev);
		}
		else {
			return rev;
		}
	}
};

int main(int arg, char * argv[]){
	Solution solution = Solution();
	/*solution.reverse(1534236469);*/
	printf("%d\n", 2147483649);
	printf("%d\n", 2147483648);
	printf("%d\n", 2147483647);
	solution.reverse(2147483648);
	_getch();
	return 1;
}