#include <iostream>
#include <string>

using namespace std;

class arrQ {
private:
	int* arr;
	int capacity;
	int n;
	int frontIndex;
	int rearIndex;
public:
	arrQ(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		n = 0;
		frontIndex = 0;
		rearIndex = 0;
	}
	int front() {
		if (n == 0) {
			return -1;
		}
		else {
			return arr[(frontIndex + 1) % capacity];
		}
	}
	void enqueue(int value) {
		if (n == capacity) {
			return;
		}
		else {
			rearIndex = (rearIndex + 1) % capacity;
			arr[rearIndex] = value;
			n++;
		}
	}
	void dequeue() {
		if (n == 0) {
			return;
		}
		else {
			frontIndex = (frontIndex + 1) % capacity;
			n--;
		}
	}
};

void play() {
	int round = 0, cardnum = 0;;
	cin >> round;
	int last_score = 0;
	int winner = 0;
	int p1_score = 0;
	int p2_score = 0;
	for (int i = 1; i <= round; i++) {
		cin >> cardnum;
		arrQ p1(cardnum);
		arrQ p2(cardnum);
		for (int a = 1; a <= cardnum; a++) {
			int p1_input;
			cin >> p1_input;
			p1.enqueue(p1_input);
		}
		for (int b = 1; b <= cardnum; b++) {
			int p2_input;
			cin >> p2_input;
			p2.enqueue(p2_input);
		}
		for (int j = 1; j <= cardnum; j++) {
			int p1_card = p1.front();
			int p2_card = p2.front();
			if (winner == 1) {
				p2_card += last_score;
			}
			if (winner == 2) {
				p1_card += last_score;
			}
			if (p1_card > p2_card) {
				last_score = p1_card - p2_card;
				winner = 1;
				p1_score++;
			}
			else if (p1_card < p2_card) {
				last_score = p2_card - p1_card;
				winner = 2;
				p2_score++;
			}
			else {
				last_score = 0;
			}

			if (p1_card != p2_card) {
				cout << "Round" << j << " " << "P" << winner << " " << last_score << endl;
			}
			else {
				cout << "Round" << j << " " << "Draw" << endl;
			}
			p1.dequeue();
			p2.dequeue();
		}
		if (p1_score > p2_score) {
			cout << "Winner P1" << endl;
		}
		else if (p1_score < p2_score) {
			cout << "Winner P2" << endl;
		}
		else {
			cout << "Draw" << endl;
		}
		winner = 0;
		last_score = 0;
		p1_score = 0;
		p2_score = 0;
	}
}
int main() {
	play();
	return 0;
}