#include <iostream>

using namespace std;

int main() {
	const int length = 100;
	cout << "�� ���� �迭�� �Է����ּ���: \n";
	char array1[length], array2[length];
	cin >> array1 >> array2;

	// �� ���� �迭 ���� Ȯ��
	int count1 = 100, count2 = 100;
	for (int i = 0; i < length; i++) {
		if (array1[i] == NULL) {
			count1 = i;
			break;
		}
	}
	for (int i = 0; i < length; i++) {
		if (array2[i] == NULL) {
			count2 = i;
			break;
		}
	}

	if (count1 != count2) {
		cout << "�� ���� �迭�� �������� �ʽ��ϴ�.\n";
		return 0;
	}
	else {
		// �� ���� �迭�� ���̰� �����ϴٸ�,
		int result = 0;

		for (int i = 0; i < count1; i++) {
			if (array1[i] != array2[i]) {
				result = -1;
				break;
			}
		}

		if (result == 0) {
			cout << "�� ���� �迭�� �����մϴ�.\n";
			return 0;
		}
		else {
			cout << "�� ���� �迭�� �������� �ʽ��ϴ�.\n";
			return 0;
		}
	}
}