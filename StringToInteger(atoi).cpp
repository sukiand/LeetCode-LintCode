/*	Implement atoi to convert a string to an integer.

	Hint: Carefully consider all possible input cases. If you want a challenge, 
	please do not see below and ask yourself what are the possible input cases.

	Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
	You are responsible to gather all the input requirements up front.

	Requirements for atoi:
	The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
	Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, 
	and interprets them as a numerical value.

	The string can contain additional characters after those that form the integral number, 
	which are ignored and have no effect on the behavior of this function.

	If the first sequence of non-whitespace characters in str is not a valid integral number, 
	or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

	If no valid conversion could be performed, a zero value is returned. 
	If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

	______(space)  +/- 0000123ab222                   return +/-123
*/

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Solution{
public:
	int atoi(const char *str){
		int rev = 0;  //store the result
		int i; //for index to the str
		int flag = 0; //+ or -, just appear once
		bool head = true;   //whitespace
		int tmp;
		for (i = 0; str[i] != '\0'; i++){
			if (head == true){
				if (str[i] == ' '){
					continue;
				}
			}
			if (flag == 0){
				if (str[i] == '+'){
					head = false;
					flag = 1;
					continue;
				}
				else if (str[i] == '-'){
					head = false;
					flag = -1;
					continue;
				}
			}
			if ('0' <= str[i] && str[i] <= '9'){
				head = false;
				if (rev == 0 && str[i] == '0'){
					continue;
				}
				else{
					/*printf("%c,%d\n", str[i], rev);*/
					tmp = rev * 10 + int((str[i] - 48));
					/*printf("%c,%d\n", str[i], rev);*/
					if (rev > 0 && tmp<0 || rev > INT_MAX/10)
					{
						if (flag == -1){
							return INT_MIN;
						}
						else{
							return INT_MAX;
						}
					}
					else{
						rev = tmp;
					}
				}
			}
			else{
				break;
			}
		}
		if (flag == -1){
			return -rev;
		}
		return rev;
	}
};

int main(int argc, char *argv[]){
	Solution so = Solution();
	printf("%d\n",so.atoi("-1"));
	printf("%d\n", so.atoi("   -00000012a"));
	printf("%d\n", so.atoi("2147483648"));

	int a = 2147483648;
	printf("2147483648 %d\n", a);
	printf("2147483649 %d\n", a+1);
	printf("2147483647 %d\n", a-1);
	_getch();
	return 1;
}