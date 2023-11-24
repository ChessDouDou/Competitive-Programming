#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	int count = 0;
	double N = 1e10;
	srand(time(0));
	for (int i = 0; i < N; i++) {
		int nums[3];
		nums[0] = rand() % 301;
		nums[1] = rand() % 301;
		if (nums[0] > nums[1])
			swap(nums[0], nums[1]);
		nums[2] = 300 - nums[1];
		nums[1] -= nums[0];
		int wins = 0, ties = 0, losses = 0;
		for (int j = 0; j < 3; j++) {
			if (nums[j] > 100)
				wins++;
			else if (nums[j] == 100)
				ties++;
			else
				losses++;
		}
		if (wins >= 2)
			count++;
		else if (ties == 3 || (ties == 1 && wins == 1 && losses == 1))
			i--;
		cout << double(count) / i * 100 << endl;
	}
	cout << double(count) / N * 100 << endl;
	return 0;
}
