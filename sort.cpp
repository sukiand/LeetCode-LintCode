#include <iostream>
#include <conio.h>
#include <vector>
#include <stdlib.h> // rand
#include <time.h>		//time

using namespace std;

class Sort{
public:
	/*void insertSort(vector<int> &array){
		vector<int>::size_type i, j;
		int length = array.size();
		int tmp;
		cout << "array 0"<<array[0] << endl;
		for (j = 1; j < length; j++){
			cout << "j: " << j << endl;
			tmp = array[j];
			for (i = j - 1; (i >= 0) && (array[i] > tmp); i--){   //the problem is, i cannot be -1. if so, it will beyong the range, error
																  // one solution is, change vector<int>::size_type to int
				array[i + 1] = array[i];
			}
			array[i + 1] = tmp;
		}
		return;
	}*/

	void insertSort(vector<int> &array){
		int i, j;
		int length = array.size();
		int tmp;
		for (j = 1; j < length; j++){
			tmp = array[j];
			for (i = j - 1; (i >= 0) && (array[i] > tmp); i--){
				array[i + 1] = array[i];
			}
			array[i + 1] = tmp;
		}
		return;
	}

	void bubbleSort(vector<int> &array){
		int i, j;
		int length = array.size();
		int tmp;
		for (j = length -1 ; j >0; j--){
			for (i = 0; i < j; i++){
				if (array[i] > array[i+1]){
					tmp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = tmp;
				}
			}
		}
	}

	void shellSort(vector<int> &array){
		int length = array.size();
		int tmp;
		int i;
		int d = length;
		bool flag = false;
		while (flag || (d > 1)){
			d = (d + 1) / 2;
			flag = false;
			for (i = 0; i < length - d; i++){
				if (array[i] > array[i + d]){
					tmp = array[i];
					array[i] = array[i + d];
					array[i + d] = tmp;
					flag = true;
				}
			}
		}
	}

	void mergeSort(vector<int> &array, int low, int high){
		int mid;
		if (high == -1)
		{
			high = array.size() - 1 ;
		}
		if (high > low)
		{
			mid = (low + high) / 2;
			mergeSort(array, low, mid);
			mergeSort(array, mid + 1, high);
			mergeSortConquer(array, low, mid, high);
		}
		return;
	}

	void mergeSortConquer(vector<int> &array, int low, int mid, int high){
		int k = low;
		int i = low;
		int j = mid + 1;
		int tmp;
		while (i<= mid && j<=high)
		{
			if (array[j] < array[i]){
				tmp = array[j];
				for (k = j; k > i; k--){			//must use decendent. all it will change the origin num.
					array[k] = array[k - 1];
				}
				array[i] = tmp;
				i++;
				j++;
			}
			else{
				i++;
			}
		}
		return;
	}

	void quickSort(vector<int> &array, int bottom, int top){
		void printVector(vector<int> target);
		int mid;
		if (top == -1)
		{
			top = array.size() - 1;
		}
		if (top > bottom){
			mid = quickSortPart(array, bottom, top);
			cout << "mid then: " << mid << endl;
			printVector(array);
			quickSort(array, bottom, mid - 1);
			quickSort(array, mid + 1, top);
		}
		return;
	}

	int quickSortPart(vector<int> &array, int bottom, int top){
		srand(time(NULL));
		int mid = rand() % (top + 1 - bottom) + bottom;
		cout << "mid is: " << mid << endl;
		int i = bottom;
		while (i < top + 1){
			if (i == mid)
			{
				i++;
				continue;
			}
			if (i < mid && array[i] > array[mid]){
				int tmp = array[i];
				for (int j = i; j < mid; j++){
					array[j] = array[j + 1];
				}
				array[mid] = tmp;
				mid--;
				continue;
			}
			if (i > mid && array[i] < array[mid]){
				int tmp = array[i];
				/*for (int j = mid; j < i; j++){
					array[j + 1] = array[j];
				}*/										// easy mistake!!!! over write!!!   over first, the shift!
				for (int j = i; j > mid; j--){
					array[j] = array[j - 1];
				}
				array[mid] = tmp;
				mid++;
				i++;
				continue;
			}
			i++;
		}
		return mid;
	}

};

	vector<int> readfromstring(string s){
		int length = s.length();
		int tmp = 0;
		vector<int> result;
		for (int i = 0; i < length; i++){
			if (s[i] == ' '){
				result.push_back(tmp);			 //push_back, is to push after the initial size.
				tmp = 0;
			}
			else{
				tmp = tmp * 10 + s[i] - 48;
			}
			if (i == length - 1 && s[i] != ' '){
				result.push_back(tmp);
			}
		}
		return result;
	}

	void printVector(vector<int> target){
		vector<int>::size_type i;
		for (i = 0; i<target.size(); i++){
			cout << target[i] << ' ';
		}
		cout << endl;
	}

int main(int argc, char *argv[]){
	string s = "2 4 3 5 1 9 7 8 19";
	vector<int> k = readfromstring(s);
	printVector(k);
	Sort sort = Sort();
	/*sort.insertSort(k);*/
	/*sort.bubbleSort(k);*/
	/*sort.shellSort(k);*/
	/*sort.mergeSort(k, 0, -1);*/
	sort.quickSort(k, 0, -1);
	printVector(k);
	_getch();
}