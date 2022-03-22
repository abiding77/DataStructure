#include <iostream>
#include <string>
using namespace std;

struct node {
	int data;
	node* next;
};

class linkedStack {
private:
	node* topNode;
	int listSize;
public:
	linkedStack() {
		listSize = 0;
		topNode = NULL;
	}
	bool empty() {
		if (listSize == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	int size() {
		return listSize;
	}
	int top() {
		if (empty()) {
			return -1;
		}
		return topNode->data;
	}
	void push(int data) {
		node* newNode = new node();
		newNode->data = data;
		newNode->next = topNode;
		topNode = newNode;
		listSize++;
	}
	int pop() {
		if (empty()) {
			return -1;
		}
		node* curNode = topNode;
		node* subNode = new node;
		topNode = topNode->next;
		subNode->data = curNode->data;
		delete curNode;
		listSize--;

		return subNode->data;
	}
};

int main() {
	linkedStack s;
	int input;
	cin >> input;
	for (int i= 0; i < input; i++) {
		string instructor;
		cin >> instructor;
		if (instructor == "empty") {
			cout << s.empty() << endl;
		}
		if (instructor == "pop") {
			cout << s.pop() << endl;
		}
		if (instructor == "size") {
			cout << s.size() << endl;
		}
		if (instructor == "push") {
			int a;
			cin >> a;
			s.push(a);
		}
		if (instructor == "top") {
			cout << s.top() << endl;
		}
	}
}