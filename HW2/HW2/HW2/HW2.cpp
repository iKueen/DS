#include <iostream>
#include <string>

using namespace std;

int powerset(string a, int b, string c)
{
	if (b == a.size()) {
		cout << c << " ";
		return 0;
	}
		powerset(a,b+1,c);
		powerset(a,b+1,c+a[b]);
	
}

int main()
{
	string a, c;
	a = "abc";
	c = "";
	powerset(a, 0, c);
	return 0;
}