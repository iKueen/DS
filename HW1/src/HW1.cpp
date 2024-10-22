#include <iostream>
using namespace std;

// 遞迴計算 Ackermann 函數
int acker(int m, int n)
{	
    // 當 m 等於 0，返回 n + 1
	if (m == 0) 
		return n + 1;
	else if (n == 0) // 當 n 等於 0，遞迴計算 acker(m-1, 1)
	{
		return acker(m - 1, 1);
	}
	else // 否則，遞迴計算 acker(m-1, acker(m, n-1))
	{
		return acker(m - 1, acker(m, n - 1));
	}
}

int main() 
{
    // 測試 Ackermann 函數，輸出結果
	cout << acker(1, 2); // 計算 A(1, 2)

	return 0;
}
