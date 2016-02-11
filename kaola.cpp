#include <iostream>
#include <conio.h>

using namespace std;

int main(int argc, char *argv[]){
	int A[] = { -1, 1, 3, 5, 6, 9 };
	int high = 5;
	int low = 0;
	int mid = (high + low) / 2;
	bool count = false;
	while (low != high){
		if (A[mid] < mid + 1){
			low = mid + 1;
			mid = (high + low) / 2;
		}
		else if (A[mid] > mid + 1){
			high = mid - 1;
			mid = (high + low) / 2;
		}
		else{
			count = true;
			break;
		}
	}
	if (count == true){
		cout << A[mid] << " " << mid + 1 << endl;
	}
	else {
		cout << "Not Found!" << endl;
	}
	_getch();
}