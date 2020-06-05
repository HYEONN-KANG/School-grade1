#include <iostream>
using namespace std;

#include <cstring>

int find(char[], char, int);

int main() {
	char str[50];
	cout << "str : ";
	cin.getline(str, 50);

	int howmany = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'k') {
			howmany++;
		}
	}

	if (howmany == 0) {
		cout << "Index of 1st k : -1 (not exist)" << endl;
		return 0;
	}

	for (int i = 1; i <= howmany; i++) {
		cout << "Index of " << i << "st k : " << find(str, 'k', i) << endl;
	}

	return 0;
}

int find(char str[], char ch, int num) {
	int index = -1, count = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (ch == str[i]) {
			count++;
			if (count == num) {
				index = i;
			}
		}
	}

	return index;
}
