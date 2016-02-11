#include <iostream>

using namespace std;

int flipBits(int A[], int n){
	int start = -1, end = -1;
	int mark = 1;
	int count = 0;
	for (int i = 0; i < n; i++){
		if (count == 0){
			if (A[i] == 0){
				count++;
				start = i;
			}
		}
		if (count > 0){
			if (A[i] == 0){
				count++;
			}
			else {
				count--;
				if (count == 0){
					end = i - 1;
				}
			}
		}
	}
}

int main(int argc, char ** argv){

}