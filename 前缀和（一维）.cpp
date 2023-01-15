/*题目：
输入一个长度为 n的整数序列。
接下来再输入 m个询问，每个询问输入一对 l,r。
对于每个询问，输出原序列中从第 l个数到第 r个数的和。

输入格式
第一行包含两个整数 n和 m。
第二行包含 n个整数，表示整数数列。
接下来 m行，每行包含两个整数 l和 r，表示一个询问的区间范围。

输出格式
共 m行，每行输出一个询问的结果。
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

const int N = 100010;

int q[N], s[N]; //一维前缀和需要两个数组

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) scanf("%d", &q[i]);

	s[0] = 0; //将前缀和数组下标为0的位置初始化为0
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + q[i]; //一维前缀和公式：s[i] = s[i-1] + a[i]

	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);

		printf("%d\n", s[r] - s[l - 1]); //求区间l到r的和；
	}
	return 0;
}