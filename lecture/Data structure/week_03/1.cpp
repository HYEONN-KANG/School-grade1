#include <iostream>
#include <string>
using namespace std;

class StackArray {
private:
	int* arr;
	int fullsize;
	int size;
	int t;

public:
	StackArray(int sz) {
		fullsize = sz;
		arr = new int[fullsize];
		t = 0;
		size = 0;
		for (int i = 0; i < fullsize; i++) {
			arr[i] = 0;
		}
	}
	int Empty();
	void empty();
	int Size();
	void top();
	void push(int e);
	void pop();
};

int StackArray::Empty() {
	return (Size()==0);
}

void StackArray::empty() {
	if (Empty())
		cout << 1 << endl;
	else
		cout << 0 << endl;
}

int StackArray::Size() {
	return size;
}

void StackArray::top() {
	if (Empty())
		cout << -1 << endl;
	else
	{
		cout << arr[t] << endl;
	}
}

void StackArray::push(int e) {
	if (Empty()) {
		arr[0] = e;
	}
	else if (t == fullsize - 1) {
		cout << "FULL" << endl;
		return;
	}
	else {
		t++;
		arr[t] = e;
	}
	size++;
}

void StackArray::pop() {
	if (Empty())
		cout << -1 << endl;
	else if (Size() == 1) {
		cout << arr[t] << endl;
		arr[t] = 0;
		size--;
	}
	else {
		cout << arr[t] << endl;
		t--;
		arr[t + 1] = 0;
		size--;
	}

}

int main() {
	int t, N;
	cin >> t >> N;

	StackArray stack(t);

	for (int i = 0; i < N; i++) {
		string oper;
		cin >> oper;

		if (oper == "empty") {
			stack.empty();
		}
		else if (oper == "top") {
			stack.top();
		}
		else if (oper == "push") {
			int e;
			cin >> e;
			stack.push(e);
		}
		else if (oper == "pop") {
			stack.pop();
		}
	}
}