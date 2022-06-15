#include <iostream>

using namespace std;

struct node {
	int key;
	int dept;
	node* parent;
	node* left;
	node* right;
	node(int key) {
		this->key = key;
		this->dept = 0;
		parent = left = right = NULL;
	}
};

class BST {
private:
	node* root;
public:
	BST() {
		root = NULL;
	}
	void play() {
		int nodeNum = 0;
		int subNum = 0;
		cin >> nodeNum >> subNum;
		for (int i = 0; i < nodeNum; i++) {
			int a;
			cin >> a;
			insert(a);
		}
		for (int j = 0; j < subNum; j++) {
			int b;
			cin >> b;
			cout << search(root, b)->dept << endl;
		}
	}
	node* search(node* curNode, int key) {
		if (curNode == NULL) return NULL;
		if (curNode->key == key)
			return curNode;
		else if (curNode->key < key)
			return search(curNode->right, key);
		else
			return search(curNode->left, key);
	}
	void insert(int key) {
		if (search(root, key) != NULL) return;
		node* newNode = new node(key);
		if (root == NULL) {
			root = newNode;
			return;
		}
		node* curNode = root;
		node* parNode = NULL;
		while (curNode != NULL) {
			parNode = curNode;
			if (curNode->key < key) {
				curNode->dept++;
				curNode = curNode->right;
			}
			else {
				curNode = curNode->left;
			}
		}
		newNode->parent = parNode;
		if (parNode->key < key) {
			parNode->right = newNode;
		}
		else {
			parNode->left = newNode;
		}
	}
};

int main() {
	BST bst;
	bst.play();
}