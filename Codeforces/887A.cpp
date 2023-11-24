#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int firstOne = -1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') {
			firstOne = i;
			break;
		}
	}
	if (firstOne == -1) {
		cout << "no" << endl;
		return 0;
	}
	int counter = 0;
	for (int i = firstOne; i < s.length(); i++)
		if (s[i] == '0')
			counter++;
	if (counter >= 6)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}
