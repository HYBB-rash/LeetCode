#include<iostream>
#include <cmath>
#include <vector>
using namespace std;
int reverseBits(int num) {
	vector<int> ans;
	long long p = pow(2, 32);
	while (p > 0) {
		ans.push_back(num / p);
		num = num % p;
		p /= 2;
	}
	int max = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == 0) {
			int count = 0;
			int left = i - 1, right = i + 1;
			while (left >= 0 && ans[left] == 1 && right < ans.size() && ans[right] == 1) {
				count += 2;
				left--, right++;
			}
			while (left >= 0 && ans[left] == 1) {
				count++;
				left--;
			}
			while (right < ans.size() && ans[right] == 1) {
				count++;
				right++;
			}
			if (count + 1 > max) max = count + 1;
		}
	}
	return max;
}
int main()
{
	cout << reverseBits(2147483647) << endl;
	return 0;
}