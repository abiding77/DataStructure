#include <iostream>
#include <string>


using namespace std;

class arrQ {
private:
	int* arr;
	int capacity;
	int n;
	int frontIndex;
	int rearIndex;
public:
	arrQ(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		n = 0;
		frontIndex = 0;
		rearIndex = 0;
	}
	int size() {
		return n;
	}
	void isEmpty() {
		if (n == 0) {
			cout << "True" << endl;
		}
		else {
			cout << "False" << endl;
		}
	}
	void front() {
		if (n == 0) {
			cout << "Empty" << endl;
		}
		else {
			cout << arr[(frontIndex + 1) % capacity] << endl;
		}
	}
	void rear() {
		if (n == 0) {
			cout << "Empty" << endl;
		}
		else {
			cout << arr[rearIndex] << endl;
		}
	}
	void enqueue(int value) {
		if (n == capacity) {
			cout << "Full" << endl;
		}
		else {
			rearIndex = (rearIndex + 1) % capacity;
			arr[rearIndex] = value;
			n++;
		}
	}
	void dequeue() {
		if (n == 0) {
			cout << "Empty" << endl;
		}
		else {
			frontIndex = (frontIndex + 1) % capacity;
			cout << arr[frontIndex] << endl;
			n--;
		}
	}
};

int main() {
	int input, size;
	cin >> size >> input;
	arrQ a(size);
	for (int i = 0; i < input; i++) {
		string s;
		cin >> s;
		if (s == "size") {
			cout << a.size() << endl;
		}
		if (s == "isEmpty") {
			a.isEmpty();
		}
		if (s == "front") {
			a.front();
		}
		if (s == "rear") {
			a.rear();
		}
		if (s == "enqueue") {
			int test;
			cin >> test;
			a.enqueue(test);
		}
		if (s == "dequeue") {
			a.dequeue();
		}
	}
	return 0;
}