#include <string>
#include <iostream>
using namespace std;
int main()
{
	long long number = 0;
	string a = "125454151511453";
	size_t b = 9;
	number = stoll(a,&b,10);
	cout << number << endl;
	return 0;
}