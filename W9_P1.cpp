#include <iostream>
#include <string>
#include <vector>



using namespace std;

struct compare {
	bool operator()(const int& e1, const int& e2) {
		return e1 > e2;
	}
};

class unsortPQ {
private:
	vector<int> seq;
public:
	unsortPQ(int size) {
		seq.assign(size, 0);
		for (int i = 0; i < size; i++) {
			cin >> seq[i];
		}

		vector<int> PQ;
		vector<int> temp;

		temp.assign(seq.size(), 0);
		PQ.assign(seq.size(), 0);

		for (int i = 0; i < seq.size(); i++) {
			PQ[i] = seq[i];
		}
		for (int i = 0; i < PQ.size(); i++) {
			temp[i] = unsortPQ::max();
			unsortPQ::removemax();
		}
		for (int i = 0; i < temp.size(); i++) {
			cout << temp[i] << " ";
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
	void removemax() {
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
	int input = 0;
	cin >> input;
	for (int i = 0; i < input; i++) {
		int num = 0;
		cin >> num;
		unsortPQ lar(num);
	}
	return 0;
}