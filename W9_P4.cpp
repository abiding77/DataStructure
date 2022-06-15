#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct compare {
	bool operator()(const int& e1, const int& e2) {
		if (e1 % 2 == 0 && e2 % 2 == 0) {
			return e1 < e2;
		}
		else if (e1 % 2 == 0) {
			return 1;
		}
		else if (e2 % 2 == 0) {
			return 0;
		}
		return e1 < e2;
	}
};

class unsortedPQ {
private:
	vector<int> seq;
public:
	void play() {
		int num = 0;
		cin >> num;
		vector<int> sortArr;
		for (int k = 0; k < num; k++) {
			int a;
			cin >> a;
			insert(a);
		}
		for (int j = 0; j < num; j++) {
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
		seq.push_back(e);
	}
	int min() {
		compare C;
		int minVal = seq[0];
		for (int i = 0; i < seq.size(); i++) {
			if (C(seq[i], minVal)) {
				minVal = seq[i];
			}
		}
		return minVal;
	}
	void removeMin() {
		compare C;
		int minIdx = 0;
		for (int i = 0; i < seq.size(); i++) {
			if (C(seq[i], seq[minIdx])) {
				minIdx = i;
			}
		}
		seq.erase(seq.begin() + minIdx);
	}
};

int main() {
	int testcase = 0;
	unsortedPQ pq;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		pq.play();
	}
}