/*题目：
输入一个 n 行 m 列的整数矩阵，
再输入 q 个询问，每个询问包含四个整数 x1,y1,x2,y2，表示一个子矩阵的左上角坐标和右下角坐标。
对于每个询问输出子矩阵中所有数的和。

输入格式
第一行包含三个整数 n，m，q。
接下来 n 行，每行包含 m 个整数，表示整数矩阵。
接下来 q 行，每行包含四个整数 x1,y1,x2,y2，表示一组询问。

输出格式
共 q行，每行输出一个询问的结果。

数据范围
1≤n,m≤1000,
1≤q≤200000,
1≤x1≤x2≤n,
1≤y1≤y2≤m,
−1000≤矩阵内元素的值≤1000
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

const int N = 1010;
int n, m, q, s[N][N]; //二维前缀和只需要一个数组

int main() {

	scanf("%d%d%d", &n, &m, &q);
	s[0][0] = 0;
	for(int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &s[i][j]);
			s[i][j] = s[i][j] - s[i - 1][j - 1] + s[i][j - 1] + s[i - 1][j]; //二维前缀和数组的公式先减后加，想着矩阵图在默写公式
		}
	}

	while (q--) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", s[x2][y2] + s[x1 - 1][y1 - 1] - s[x2][y1 - 1] - s[x1 - 1][y2]); //求区间矩阵和公式，注意复习时先想着矩阵图在默写公式
	}
	return 0;
}