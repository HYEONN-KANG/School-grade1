#include <iostream>

using namespace std;

int main() {
	const int length = 100;
	char array[length];
	cout << "char �迭�� �Է��ϼ���: ";
	cin >> array;

	cout << "�Ųٷ� �迭�� �����Ͽ��� �迭��: ";
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