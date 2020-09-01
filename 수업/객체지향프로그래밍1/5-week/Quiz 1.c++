// prin star diamond and calcualte factorial

#include <iostream>

using namespace std;

void printStar(int);

void factorial(int);

int main() {
	int num;
	cout << "Please enter an integer : ";
	cin >> num;
	
    printStar(num);

    factorial(num);
}

void printStar(int x){
    for (int i = 1; i <= x; i++) {
		for (int j = i; j <= x - 1; j++) {
			cout << " ";
		}
		for (int k = 1; k <= 2 * i - 1; k++) {
			cout << "*";
		}cout << endl;
	}

	for (int i = 1; i < x; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		for (int k = 2 * x - 1; k >2*i; k--) {
			cout << "*";
		}cout << endl;
	}cout << endl;
}

void factorial(int y){
	int output = 1;
	for (int i = y; i >= 1; i--) {
		output = output * i;
	}
	cout << y << "!" << "= " << output;
}