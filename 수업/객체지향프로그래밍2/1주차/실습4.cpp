#include <iostream>

using namespace std;

int main() {
	const int length = 100;
	cout << "두 개의 배열을 입력해주세요: \n";
	char array1[length], array2[length];
	cin >> array1 >> array2;

	// 두 개의 배열 길이 확인
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
		cout << "두 개의 배열은 동일하지 않습니다.\n";
		return 0;
	}
	else {
		// 두 개의 배열의 길이가 동일하다면,
		int result = 0;

		for (int i = 0; i < count1; i++) {
			if (array1[i] != array2[i]) {
				result = -1;
				break;
			}
		}

		if (result == 0) {
			cout << "두 개의 배열은 동일합니다.\n";
			return 0;
		}
		else {
			cout << "두 개의 배열은 동일하지 않습니다.\n";
			return 0;
		}
	}
}