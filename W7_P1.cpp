#include <iostream>

#include <vector>

#include <string>



using namespace std;



struct node {

	int data;

	node* parent;

	vector<node*> childList;

	node(int data, node* parent) {

		this->data = data;

		this->parent = parent;

	}

};



class Tree {

private:

	node* root;

	vector<node*> nodeList;

	int dept;

	int find(int data, vector<node*>& list) {

		for (int i = 0; i < list.size(); i++)

			if (list[i]->data == data)

				return i;

		return -1;

	}

public:

	Tree() {

		root = new node(1, NULL);

		nodeList.push_back(root);

		this->dept = 1;

	}

	void insertNode(int parData, int data) {

		if (find(data, nodeList) != -1) {

			return;

		}

		int idx = find(parData, nodeList);

		if (idx == -1) {

			return;

		}

		node* parNode = nodeList[idx];

		node* newNode = new node(data, parNode);

		parNode->childList.push_back(newNode);

		nodeList.push_back(newNode);

		return;

	}

	void postorder(node* curNode) {

		for (int i = 0; i < curNode->childList.size(); i++) {

			if (curNode->childList[i] != NULL) {

				++dept;

			}

			postorder(curNode->childList[i]);

		}

		dept--;

		//cout << curNode->data << " ";

		cout << dept << " ";

		cout << endl;

	}

	void play() {

		int input;

		int parData, data;

		cin >> input;

		for (int j = 0; j < input - 1; j++) {

			cin >> parData >> data;

			insertNode(parData, data);

		}

		postorder(root);

	}

};



int main() {

	int input;

	cin >> input;

	for (int i = 0; i < input; i++) {

		Tree t;

		t.play();

	}

}