#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << pow(2, n) - 1 << endl;
	stack<int> t1, t2, t3;
	t1.push(-1);
	t2.push(-1);
	t3.push(-1);
	for (int i = n; i >= 1; i--)
		t1.push(i);
	int counter = 0;
	if (n % 2 == 0) {
		while (counter != 2) {
			if ((t1.top() < t2.top() && t1.top() != -1) || t2.top() == -1) {
				t2.push(t1.top());
				t1.pop();
				cout << "1 2" << endl;
			}
			else if (t2.top() != -1) {
				t1.push(t2.top());
				t2.pop();
				cout << "2 1" << endl;
			}
			if ((t1.top() < t3.top() && t1.top() != -1) || t3.top() == -1) {
				t3.push(t1.top());
				t1.pop();
				cout << "1 3" << endl;
			}
			else if (t3.top() != -1) {
				t1.push(t3.top());
				t3.pop();
				cout << "3 1" << endl;
			}
			if ((t2.top() < t3.top() && t2.top() != -1) || t3.top() == -1) {
				t3.push(t2.top());
				t2.pop();
				cout << "2 3" << endl;
			}
			else if (t3.top() != -1) {
				t2.push(t3.top());
				t3.pop();
				cout << "3 2" << endl;
			}
			counter = (t1.top() == -1) + (t2.top() == -1) + (t3.top() == -1);
		}
	}
	else {
		while (counter != 2) {
			if ((t1.top() < t3.top() && t1.top() != -1) || t3.top() == -1) {
				t3.push(t1.top());
				t1.pop();
				cout << "1 3" << endl;
			}
			else if (t3.top() != -1) {
				t1.push(t3.top());
				t3.pop();
				cout << "3 1" << endl;
			}
			counter = (t1.top() == -1) + (t2.top() == -1) + (t3.top() == -1);
			if (counter == 2) break;
			if ((t1.top() < t2.top() && t1.top() != -1) || t2.top() == -1) {
				t2.push(t1.top());
				t1.pop();
				cout << "1 2" << endl;
			}
			else if (t2.top() != -1) {
				t1.push(t2.top());
				t2.pop();
				cout << "2 1" << endl;
			}
			counter = (t1.top() == -1) + (t2.top() == -1) + (t3.top() == -1);
			if (counter == 2) break;
			if ((t2.top() < t3.top() && t2.top() != -1) || t3.top() == -1) {
				t3.push(t2.top());
				t2.pop();
				cout << "2 3" << endl;
			}
			else if (t3.top() != -1) {
				t2.push(t3.top());
				t3.pop();
				cout << "3 2" << endl;
			}
			counter = (t1.top() == -1) + (t2.top() == -1) + (t3.top() == -1);
		}
	}
	return 0;
}