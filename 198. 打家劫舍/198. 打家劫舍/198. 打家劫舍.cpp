#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n = 0, cnt = 0;
void DFS(int index, int dep, int mon, vector<int>& nums) {
	
	if (dep == n) {
		if (mon > cnt)
			cnt = mon;
		return;
	}
	if (index >= nums.size()) return;
	for (int i = index; i < nums.size(); i++)
		DFS(i + 2, dep + 1, mon + nums[i], nums);
}
int rob(vector<int>& nums) {
	n = (nums.size() + 1) / 2, cnt = 0;
	DFS(0, 0, 0, nums);
	return cnt;
}
int main()
{
	vector<int> num(4);
	for (int i = 0; i < 4; i++) cin >> num[i];
	cout << rob(num) << endl;
	return 0;
}