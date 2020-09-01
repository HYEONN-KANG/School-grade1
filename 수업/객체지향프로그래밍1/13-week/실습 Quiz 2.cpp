#include <iostream>

using namespace std;

class circle {
public:
	void getarea(int r_) {
		if (r_ >= 0) {
			r = r_;
			cout << "원의 area는  : " << r * r * double(3.14) << endl;
		}
		else {
			cout << "r값을 잘못 입력하셨습니다." << endl;
		}
	}
private:
	int r;
};

class rectangle {
public:
	void getarea(int h_, int d_) {
		if (h_ >= 0 && d_ >= 0) {
			h = h_;
			d = d_;
			cout << "직사각형의 area는: " << h * d << endl;
		}
		else {
			cout << "h와 d값을 잘못 입력하셨습니다." << endl;
		}
	}
private:
	int h, d;
};

int main() {
	circle one;
	rectangle box;
	cout << "도형의 넓이를 계산합니다."
		<< "1은 circle, 2는 rectangle, 둘 중 하나를 선택하세요. : ";
	int choice;
	while (true) {
		cin >> choice;
		if (choice == 1 || choice == 2)
			break;
	}

	if (choice == 1) {
		cout << "원의 r값을 입력하세요: ";
		int r;
		cin >> r;

		one.getarea(r);
	}
	else {
		cout << "직사각형의 h와 d값을 입력하세요: ";
		int h, d;
		cin >> h >> d;

		box.getarea(h, d);
	}
}