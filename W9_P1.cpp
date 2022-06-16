#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct compare {
	bool operator()(const int& e1, const int& e2) const {
		return e1 < e2;
	}
};

class sortedPQ {
private:
	vector<int> seq;
public:
	void play() {
		int seqSize = 0;
		cin >> seqSize;
		for (int k = 0; k < seqSize; k++) {
			int a;
			cin >> a;
			insert(a);
		}
		vector<int> sortArr;
		for (int j = 0; j < seqSize; j++) {
			sortArr.push_back(min());
			removeMin();
		}
		for (int z = 0; z < sortArr.size(); z++) {
			cout << sortArr[z] << " ";
		}
		cout << endl;
	}
	
	int size() {
		return seq.size();
	}
	bool empty() {
		return (seq.size() == 0);
	}
	void insert(int e) {
		compare C;
		int idx = 0;
		for (idx = 0; idx < seq.size(); idx++) {
			if (C(seq[idx], e)) break;
		}
		seq.insert(seq.begin() + idx,e);
	}
	int min() {
		if (empty()) return -1;
		return seq.back();
	}
	void removeMin() {
		if (empty()) return;
		seq.pop_back();
	}
};

int main() {
	int testcase = 0;
	cin >> testcase;
	sortedPQ s;
	for (int i = 0; i < testcase; i++) {
		s.play();
	}
}