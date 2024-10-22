#include <iostream>
#include <string>

using namespace std;

// 遞迴生成冪集的函式
int powerset(string a, int b, string c)
{
    // 當 b 等於字串長度時，輸出當前生成的子集
	if (b == a.size()) {
		cout << c << " "; // 輸出子集
		return 0; // 結束當前遞迴
	}
	// 遞迴不選擇當前字符
	powerset(a, b + 1, c);
	// 遞迴選擇當前字符
	powerset(a, b + 1, c + a[b]);
}

int main()
{
    // 定義字符串 a 和空字符串 c
	string a, c;
	a = "abc"; // 設定字串為 "abc"
	c = ""; // 初始化空字符串
	powerset(a, 0, c); // 開始遞迴生成冪集
	return 0;
}
