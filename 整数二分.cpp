﻿/*题目：
给定一个按照升序排列的长度为 n 的整数数组，以及 q 个查询。
对于每个查询，返回一个元素 k 的起始位置和终止位置（位置从 0 开始计数）。
如果数组中不存在该元素，则返回 -1 -1。

输入格式
第一行包含整数 n 和 q，表示数组长度和询问个数。
第二行包含 n 个整数（均在 1∼10000 范围内），表示完整数组。
接下来 q 行，每行包含一个整数 k，表示一个询问元素。

输出格式
共 q 行，每行包含两个整数，表示所求元素的起始位置和终止位置。
如果数组中不存在该元素，则返回 -1 -1。
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N];

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	while (q--) {

		int k;
		scanf("%d", &k);

		int l = 0, r = n - 1;
		while (l < r) { //此种方式是找左边界
			int mid = (l + r) >> 1; //注意边界，当下面r=mid时（l+r）就不需要在额外+1
			if (a[mid] >= k) r = mid;
			else l = mid + 1;
		}

		if (a[l] != k) cout << "-1 -1" << endl;
		else {
			cout << l << " ";

			int l = 0, r = n - 1;
			while (l < r) { //此种方式是找右边界
				int mid = (l + r + 1) >> 1; //当下面l=mid时（l+r）就需要额外+1，因为c++是下取整，我们要保证（l+r+1)/2取到r，而不是（l+r）/2取到l进而造成死循环
				if (a[mid] <= k) l = mid;
				else r = mid - 1;
			}
			cout << l << endl;
		}
	}
	return 0;
}