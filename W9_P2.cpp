#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct compare {
	bool operator()(const int& e1, const int& e2) const {
		if (e1 % 2 && e2 % 2) {
			return e1 > e2;
		}
		else if (e1 % 2) {
			return 1;
		}
		else if (e2 % 2) {
			return 0;
		}
		return e1 > e2;
	}
};

class unsortedSeqPQ {
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
			sortArr.push_back(max());
			removeMax();
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
		seq.push_back(e);
	}
	int max() {
		if (empty()) return -1;
		compare C;
		int maxVal = seq[0];
		for (int i = 0; i < seq.size(); i++) {
			if (C(seq[i], maxVal)) {
				maxVal = seq[i];
			}
		}
		return maxVal;
	}
	void removeMax() {
		if (empty()) return;
		compare C;
		int maxIdx = 0;

		for (int i = 0; i < seq.size(); i++) {
			if (C(seq[i], seq[maxIdx])) {
				maxIdx = i;
			}
		}
		seq.erase(seq.begin() + maxIdx);
	}
};

int main() {
	int testcase = 0;
	cin >> testcase;
	unsortedSeqPQ s;
	for (int i = 0; i < testcase; i++) {
		s.play();
	}
}