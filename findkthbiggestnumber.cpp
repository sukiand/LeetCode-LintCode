#include <iostream>

using namespace std;

int findKthbiggest(int A[], int n, int B[], int m, int k){
	if (k > m + n){
		return -1;
	}
	if (m == 0) return A[k - 1];
	if (n == 0) return B[k - 1];
	if (k == 1) return A[0] > B[0] ? A[0] : B[0];
	int ia, ib;
	if (n < m){
		ia = k / 2 > n ? n : k / 2;
		ib = k - ia;
	}
	else{
		ib = k / 2 > m ? m : k / 2;
		ia = k - ib;
	}
	if (A[ia-1] == B[ib-1]) return A[ia-1];
	//abandom part of A or part of B
	else if (A[ia-1] > B[ib-1]) return findKthbiggest(A + ia, n - ia, B, m , k - ia);
	else return findKthbiggest(A, n , B + ib, m - ib, k - ib);
}

int main(int argc, char ** argv){
	int A[] = { 7,6,5,4,3,2,1 };
	int B[] = { 9,7,5,3,1 };
	cout << findKthbiggest(A, 7, B, 5, 1);
	cout << findKthbiggest(A, 7, B, 5, 2);
	cout << findKthbiggest(A, 7, B, 5, 3);
	cout << findKthbiggest(A, 7, B, 5, 4);
	cout << findKthbiggest(A, 7, B, 5, 5);
	cout << findKthbiggest(A, 7, B, 5, 6);
	cout << findKthbiggest(A, 7, B, 5, 7);
	cout << findKthbiggest(A, 7, B, 5, 8);
	cout << findKthbiggest(A, 7, B, 5, 9);
	cout << findKthbiggest(A, 7, B, 5, 10);
	cout << findKthbiggest(A, 7, B, 5, 11);
	cout << findKthbiggest(A, 7, B, 5, 12);
	cout << findKthbiggest(A, 7, B, 5, 13);
	getchar();
}