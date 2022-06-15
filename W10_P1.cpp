#include <iostream>
#include <vector>
#include <string>

using namespace std;

class heap {
private:
	vector<int> arr;
	void swap(int idx1, int idx2) {
		arr[0] = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = arr[0];
	}
	void upHeap(int idx) {
		if (idx == 1) return;
		int parent = idx / 2;
		if (arr[parent] > arr[idx]) {
			swap(parent, idx);
			upHeap(parent);
		}
	}
	void downHeap(int idx) {
		int left = 2 * idx;
		int right = 2 * idx + 1;
		int child;

		if (left > size()) {
			return;
		}
		else if (left == size()) {
			child = left;
		}
		else {
			if (arr[left] <= arr[right]) child = left;
			else child = right;
		}

		if (arr[child] < arr[idx]) {
			swap(child, idx);
			downHeap(child);
		}
	}
public:
	heap() {
		arr.push_back(0);
	}
	int size() {
		return arr.size() - 1;
	}
	bool empty() {
		return (arr.size() == 1);
	}
	void insert(int e) {
		arr.push_back(e);
		upHeap(size());
	}
	int top() {
		if (empty()) return -1;
		return arr[1];
	}
	void pop() {
		if (empty()) {
			cout << "-1" << endl;
			return;
		}
		swap(1, size());
		cout << arr[size()] << endl;
		arr.pop_back();
		downHeap(1);
	}
	void print() {
		if (empty()) {
			cout << "-1" << endl;
			return;
		}
		for (int i = 1; i<arr.size(); i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	int testcase = 0;
	cin >> testcase;
	heap hp;
	for (int i = 0; i < testcase; i++) {
		string s;
		cin >> s;
		if (s == "insert") {
			int a;
			cin >> a;
			hp.insert(a);
		}
		if (s == "size") {
			cout << hp.size() << endl;
		}
		if (s == "isEmpty") {
			cout << hp.empty() << endl;
		}
		if (s == "pop") {
			hp.pop();
		}
		if (s == "top") {
			cout << hp.top() << endl;
		}
		if (s == "print") {
			hp.print();
		}
	}
	return 0;
}