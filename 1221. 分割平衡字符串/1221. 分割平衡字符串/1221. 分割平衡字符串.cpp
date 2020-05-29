#include<string>
#include <iostream>
#include <stack>
#include<algorithm>
using namespace std;
int balancedStringSplit(string s) {
	stack<char> st;
	st.push(s[0]);
	int ans = 0;
	for (int i = 1; i < s.size(); i++) {
		if (!st.empty()&&st.top() != s[i]) st.pop();
		else st.push(s[i]);
		if (st.empty()) ans++;
	}
	return ans;
}
int main()
{
	string temp;
	cin >> temp;
	cout << balancedStringSplit(temp);
	return 0;
}