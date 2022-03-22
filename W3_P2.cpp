#include <iostream>
#include <string>

using namespace std;


class StackCal {
private:
	int* arr;
	int topIndex;
	int capacity;
public:
	StackCal(int capacity) {
		arr = new int[capacity];
		topIndex = -1;
		this->capacity = capacity;
	}
	bool empty() {
		if (topIndex == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	int size() {
		return topIndex + 1;
	}
	void push(int data) {
		if (size() == capacity) {
			return;
		}
		else {
			arr[++topIndex] = data;
		}
	}
	int pop() {
		if (empty()) {
			return -1;
		}
		return arr[topIndex--];
	}
	int top() {
		if (empty()) {
			return -1;
		}
		return arr[topIndex];
	}
};

int Calcul(string exp) {
	StackCal sc(100);
	int result , a, b = 0;
	char ch;
	for (int i = 0; i < exp.length(); i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			result = ch - '0';
			sc.push(result);
		}
		else {
			a = sc.pop();
			b = sc.pop();
			if (ch == '+') {
				sc.push(b + a);
			}
			if (ch == '-') {
				sc.push(b - a);
			}
			if (ch == '*') {
				sc.push(b * a);
			}
			if (ch == '/') {
				sc.push(b / a);
			}
		}
	}
	return sc.pop();
}
int main() {
	int input;
	cin >> input;
	for (int i = 0; i < input; i++) {
		string s;
		cin >> s;
		cout << Calcul(s) << endl;
	}
}