#include <iostream>
#include <string>

using namespace std;

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

struct entry {
	int key;
	string value;
	int valid;
	entry() {
		key = 0;
		value = "";
		valid = NOITEM;
	}
	entry(int key, string value) {
		this->key = key;
		this->value = value;
		valid = ISITEM;
	}
	void erase() {
		valid = AVAILABLE;
	}
};

class hashTable {
private:
	entry* table;
	int capacity;
	int divisor;
	int hashFnc(int key) {
		return key % capacity;
	}
	int hashFnc2(int key) {
		return divisor - (key % divisor);
	}
public:
	hashTable(int N, int M) {
		capacity = N;
		divisor = M;
		table = new entry[capacity];
		return;
	}
	void put(int key, string value) {
		int index = hashFnc(key);
		int probe = 1;
		while (table[index].valid == ISITEM && probe <= capacity) {
			index = hashFnc(index + hashFnc2(key));
			probe++;
		}
		if (probe > capacity) return;
		table[index] = entry(key, value);
		cout << probe << endl;
		return;
	}
	string erase(int key) {
		int index = hashFnc(key);
		int probe = 1;
		string tmp;
		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				tmp = table[index].value;
				table[index].erase();
				return tmp;
			}
			index = hashFnc(index + hashFnc2(key));
			probe++;
		}

		return "None";
	}
	string find(int key) {
		int index = hashFnc(key);
		int probe = 1;
		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				return table[index].value;
			}
			index = hashFnc(index + hashFnc2(key));
			probe++;
		}
		return "None";
	}
	void vacant() {
		int emptySize = 0;
		for (int i = 0; i < capacity; i++) {
			if (table[i].valid != ISITEM) {
				emptySize++;
			}
		}
		cout << emptySize << endl;
	}
};

int main() {
	int testcase = 0;
	int tableSize = 0;
	int m = 0;
	cin >> testcase >> tableSize >> m;
	hashTable ht(tableSize, m);
	for (int i = 0; i < testcase; i++) {
		string s;
		cin >> s;
		if (s == "put") {
			int key;
			string value;
			cin >> key >> value;
			ht.put(key, value);
		}
		if (s == "erase") {
			int key;
			cin >> key;
			cout << ht.erase(key) << endl;
		}
		if (s == "find") {
			int key;
			cin >> key;
			cout << ht.find(key) << endl;
		}
		if (s == "vacant") {
			ht.vacant();
		}
	}
	return 0;
}