#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
vector<int> ans;
void input()
{
	int i = 0;
	cin >> i;
	ans.assign(i, 0); 
	while(i>0)
	{
		cin>>ans[i - 1];
		i--;
	}
}
void toPrint(vector<int> ans)
{
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
}
void shit(int k)
{
	vector<int> table;
	int len = k;
	table.resize(ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		table[(len + i) % ans.size()] = i;
	}
	int index = 0;
	int temp = ans[index];
	while (table[index]!=index)
	{
		if (table[index] == 0)
			ans[index] = temp;
		else
			ans[index] = ans[table[index]];
		int copy = index;
		index = table[index];
		table[copy] = copy;
	}
}

int main()
{
	input();
	toPrint(ans);
	shit(3);
	toPrint(ans);
	return 0;
}