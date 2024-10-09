#include <iostream>
using namespace std;

int acker(int m,int n)
{	
	if (m== 0) 
		return n + 1;
	else if (n == 0)
	{
		return acker(m - 1, 1);
	}
	else
	{
		return acker(m - 1, acker(m, n - 1));
	}

}

int main() 
{
	cout << acker(1,2);

	return 0;

}