#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	const int num = 20;

	int array[num];

	for (int i = 0; i < num; i++) {
		array[i] = rand() % 991 + 10;
	}

	cout << "�������� ������ 20���� ����: ";

	for (int i = 0; i < num; i++) {
		cout << array[i] << " ";
	}

	int input;
	cout << "\n" << "ã������ ���� �Է��ϼ���: ";
	cin >> input;

	for (int i = 0; i < num; i++) {
		if (input == array[i]) {
			cout << "ã������ ���� index����: " << i << " ��° �Դϴ�.\n";
			break;
		}
	}

	return 0;
}