#include <iostream>

using namespace std;

class Array_first {
private:
	int* arr;
	int arrsize;
public:
	Array_first(int sz) {
		this->arrsize = sz;
		this->arr = new int[arrsize];
		for (int i = 0; i < sz; i++) {
			arr[i] = 0;
		}
	}

	void add(int idx, int value) {
		for (int i = arrsize - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = value;
	}

	void remove(int idx) {
		for (int i = idx + 1; i < arrsize; i++) {
			arr[i - 1] = arr[i];
		}
		arr[arrsize - 1] = 0;
	}
	void set(int idx, int value) {
		arr[idx] = value;
	}
	void print() {
		for (int i = 0; i < arrsize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void find(int idx) {
		int result = 0;
		bool check = true;
		for (int i = 0; i < arrsize; i++) {
			if (arr[i] == idx) {
				result = i;
				break;
			}
			else
				result = -1;
			
		}
		cout << result << endl;
	}
};

int main() {
	int size, cases;
	cin >> cases >> size;
	Array_first arr(size);
	for (int i = 0; i < cases; i++) {
		string case_name;
		cin >> case_name;
		if (case_name == "add") {
			int i, value;
			cin >> i >> value;
			arr.add(i,value);
		}
		if (case_name == "print") {
			arr.print();
		}
		if (case_name == "remove") {
			int i;
			cin >> i;
			arr.remove(i);
		}
		if (case_name == "set") {
			int i, value;
			cin >> i >> value;
			arr.set(i, value);
		}
		if (case_name == "find") {
			int i;
			cin >> i;
			arr.find(i);
		}
	}
	return 0;
}