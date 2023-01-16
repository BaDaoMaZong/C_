/*
题目：
输入一个长度为 n 的整数序列。
接下来输入 m 个操作，每个操作包含三个整数 l,r,c，表示将序列中 [l,r] 之间的每个数加上 c。
请你输出进行完所有操作后的序列。

输入格式
第一行包含两个整数 n 和 m。
第二行包含 n 个整数，表示整数序列。
接下来 m 行，每行包含三个整数 l，r，c，表示一个操作。

输出格式
共一行，包含 n 个整数，表示最终序列。

数据范围
1≤n,m≤100000,
1≤l≤r≤n,
−1000≤c≤1000,
−1000≤整数序列中元素的值≤1000
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N], b[N]; //一维差分表面上写两个数组，实质上其实只用到b数组

void insert(int l, int r, int c) { //构造一维差分数组实质上就一个操作

	b[l] += c;
	b[r + 1] -= c;
}

int main() { //差分不考虑如何构造，只考虑如何更新插入

	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]); //假设a数组所有数据都为0，此时b就理所应当的为a的差分数组了
		insert(i, i, a[i]); //在同一个位置上向b数组中插入a数组中相应的数，插入完成后b数组就成为了a的差分数组
	}

	while (m--) {
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		insert(l, r, c);
	}
	
	for (int i = 1; i <= n; i++) {
		b[i] += b[i - 1]; //在b数组中求一遍前缀和后所形成的新数组就是a数组
		printf("%d ", b[i]);
	}

	return 0;
}
