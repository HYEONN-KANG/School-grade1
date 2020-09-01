#include <iostream>

using namespace std;

int main() {
	const int length = 100;
	char array[length];
	cout << "char 배열을 입력하세요: ";
	cin >> array;

	cout << "거꾸로 배열을 생성하였고 배열은: ";
	int end = 100;
	for (int i = 0; i < length; i++) {
		if (array[i] == NULL) {
			end = i;
			break;
		}
	}

	for (int i = end - 1; i >= 0; i--) {
		cout << array[i];
	}
	cout << "\n";

	return 0;
}