#include <iostream>
using namespace std;

#include <cstring>

int typing(const char*, char*);

int main() {
	const char *sentence = "Hello World!";
	char input[50];
	while (true) {
		cout << sentence << endl;
		cout << "type sentence above: ";
		cin.getline(input, 50);

		if (typing(sentence, input) == 1) {
			break;
		}
		cout << endl;
	}

	return 0;
}

int typing(const char* sentence, char* input) {
	if (strcmp(sentence, input) == 0) {
		cout << "Corrence Answer !" << endl;
		return 1;
	}
	else {
		cout << "Incorrence Answer !" << endl;
		return -1;
	}
}