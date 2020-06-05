// Write a function that prints the address value and the element value by inputting the size of the array and array.
// function prototype : void printarrAdv(int* arr, int length);

#include <iostream>
using namespace std;

void printarrAdv(int* arr, int length);

int main() {
	int array[5] = { 10, 20, 30, 40, 50 };
	printarrAdv(array, 5);
}

void printarrAdv(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		cout << "arr + " << i << " : " << arr + i
			 << "\t" << "&arr[" << i << "] : " << &arr[i] << endl;
	}
	for (int i = 0; i < length; i++) {
		cout << "*(arr + " << i << ") : " << *(arr + i)
			<< "\t\t" << "arr[" << i << "] : " << arr[i] << endl;
	}
}