/*There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
*/

/*  1 what is median, need to judge whether m+n is odd or even
	2 some special cases. such as A[], B[1];
	3 some ending, when A is short and B is long, so sometimes A will end soon.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n){
		int flag_median;
		int flag_odd;
		int i = 0, j = 0;
		double median[2];

		if ((m + n) & 1 == 1){
			flag_odd = 1;
			flag_median = (m + n + 1) / 2 ;
		}
		else{
			flag_odd = 0;
			flag_median = (m + n) / 2;
		}

		do{
			if ( i == m ){
				median[0] = compare(B[j], j);
			}
			else if ( j == n ){
				median[0] = compare(A[i], i);
			}
			else{
				median[0] = compare(A[i], i, B[j], j);
			}
			flag_median--;
		} while (flag_median != 0);

		if (flag_odd == 0){
			if (i == m){
				median[1] = compare(B[j], j);
			}
			else if (j == n){
				median[1] = compare(A[i], i);
			}
			else{
				median[1] = compare(A[i], i, B[j], j);
			}
			return (median[0] + median[1]) * 0.5;
		}
		else{
			return median[0];
		}
	}

	int compare(int x, int &i){
		i++;
		return x;
	}

	int compare(int x, int &i, int y, int &j){
		if (x > y){
			j++;
			return y;
		}
		else{
			i++;
			return x;
		}
	}
};