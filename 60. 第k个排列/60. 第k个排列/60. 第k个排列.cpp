#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string ans, tempAns;
bool flag = false;
int cnt = 0, hashTable[11] = { 0 };
void DFS(int n, int k,int dep) {
	if (flag == true) return;
	if (dep == n) {
		if(cnt==k-1)
		{
			ans = tempAns;
			flag = true;
			return;
		}
		else cnt++;
	}
	for (int i = 0; i < n; i++) {
		if (hashTable[i + 1] == 1) continue;
		string temp = to_string(i + 1);
		hashTable[i + 1] = 1;
		for (auto it = temp.begin(); it != temp.end(); it++)
			tempAns.push_back(*it);
		DFS(n, k,dep+1);
		for (auto it = temp.begin(); it != temp.end(); it++)
			tempAns.pop_back();
		hashTable[i + 1] = 0;
	}
}
string getPermutation(int n, int k) {
	DFS(n, k,0);
	return ans;
}
int main()
{
	int n = 3, k = 3;
	cout << getPermutation(n, k) << endl;
	return 0;
}