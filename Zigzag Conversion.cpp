/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Solution{
public:
	string convert(string s, int nRows){
		int nLength = (s.length() - 1 ) / nRows + 1;
		char * stringOut = (char *)malloc(nRows * (nLength+1) * sizeof(char));
		int i, j, index = 0;
		//init
		
		for (j = 0; j < nLength; j ++){
			if (j % 2 == 0){
				for (i = 0; i < nRows; i++){
					if (s[index] == '\n')
					{
						break;
					}
					stringOut[j + i*nLength + i] = s[index];
					index++;
				}
			}
			else {
				if (s[index] == '\n')
				{
					break;
				}
				stringOut[j] = ' ';
				stringOut[j + nLength + 1] = s[index];
				index++;
				stringOut[j + nLength * 2 + 2] = ' ';
			}
		}

		return stringOut;
	}
};

int main(int argv, char *args[]){
	Solution solution;
	printf("%s\n",solution.convert("testback", 2));
	_getch();
	return 1;
}