#include <iostream>

using namespace std;

class circle {
public:
	void getarea(int r_) {
		if (r_ >= 0) {
			r = r_;
			cout << "���� area��  : " << r * r * double(3.14) << endl;
		}
		else {
			cout << "r���� �߸� �Է��ϼ̽��ϴ�." << endl;
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
			cout << "���簢���� area��: " << h * d << endl;
		}
		else {
			cout << "h�� d���� �߸� �Է��ϼ̽��ϴ�." << endl;
		}
	}
private:
	int h, d;
};

int main() {
	circle one;
	rectangle box;
	cout << "������ ���̸� ����մϴ�."
		<< "1�� circle, 2�� rectangle, �� �� �ϳ��� �����ϼ���. : ";
	int choice;
	while (true) {
		cin >> choice;
		if (choice == 1 || choice == 2)
			break;
	}

	if (choice == 1) {
		cout << "���� r���� �Է��ϼ���: ";
		int r;
		cin >> r;

		one.getarea(r);
	}
	else {
		cout << "���簢���� h�� d���� �Է��ϼ���: ";
		int h, d;
		cin >> h >> d;

		box.getarea(h, d);
	}
}