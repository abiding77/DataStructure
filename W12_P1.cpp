#include <iostream>
#include <string>

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

using namespace std;

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
	int hashFnc(int key) {
		return key % capacity;
	}
public:
	hashTable(int N) {
		capacity = N;
		table = new entry[capacity];
		return;
	}
	void put(int key, string value) {
		int index = hashFnc(key);
		int probe = 1;
		while (table[index].valid == ISITEM && probe <= capacity) {
			index = hashFnc(index + 1);
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
		string tmp = "";
		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				tmp = table[index].value;
				table[index].erase();
				return tmp;
			}
			index = hashFnc(index + 1);
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
			index = hashFnc(index + 1);
			probe++;
		}
		return "None";
	}
	void vacant() {
		int hashSize = 0;
		for (int i = 0; i < capacity; i++) {
			if (table[i].valid != ISITEM) {
				hashSize++;
			}
		}
		cout << hashSize << endl;
		return;
	}

};

int main() {
	int testcase = 0;
	int m = 0;
	cin >> testcase >> m;
	hashTable ht(m);
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