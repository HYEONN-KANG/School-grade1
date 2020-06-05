#include <iostream>
using namespace std;

#include <cstring>

int main() {
	const int arrsize = 3;
	const char* arr[arrsize] = { "abc", "def", "ghi" };

	cout << "char *arr[3] = { \"abc\", \"def\", \"ghi\" }" << endl;

	char temp[20] = "";
	for (int i = 0; i < arrsize; i++) {
		strcat_s(temp, arr[i]);
	}

	cout << "temp[20] = ";
	for (int i = 0; i < strlen(temp); i++) {
		cout << temp[i];
	}cout << endl;
}