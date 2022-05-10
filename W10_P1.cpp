#include <iostream>

#include <vector>

#include <string>



using namespace std;

// heap-order

// 루트를 제외한 모든 트리의 우선순위는 부모 노드의 우선순위보다 낮거나 같음

// min heap key(parent(v)) < key(v)

// max heap key(parent(v)) >= key(v)

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
		if (arr[parent] < arr[idx]) {
			swap(parent, idx);
			upHeap(parent);
		}
	}
	void downHeap(int idx) {
		int left = 2 * idx;
		int right = 2 * idx + 1;
		int child;
		if (left > size()) return;
		else if (left == size()) {
			child = left;
		}
		else {
			if (arr[left] > arr[right]) child = left;
			else child = right;
		}

		if (arr[child] > arr[idx]) {
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

		for (int i = 1; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	int top() {
		if (empty()) {
			return -1;
		}
		return arr[1];
	}
};



int main() {

	int input = 0;
	cin >> input;
	heap hp;

	for (int i = 0; i < input; i++) {

		string s;
		cin >> s;

		if (s == "isEmpty") {
			cout << hp.empty() << endl;
		}
		if (s == "insert") {
			int num;
			cin >> num;
			hp.insert(num);
		}

		if (s == "print") {
			hp.print();
		}
		if (s == "size") {
			cout << hp.size() << endl;
		}
		if (s == "top") {
			cout << hp.top() << endl;
		}
		if (s == "pop"){
			hp.pop();
		}
	}
	return 0;
}