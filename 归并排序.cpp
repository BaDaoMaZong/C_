#define _CRT_SECURE_NO_WARNINGS //编译器问题，下面的scanf在此编译器上并不安全

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int q[N], temp[N];

void merge_sort(int q[], int l, int r) {

	if (l >= r) return; //只有一个数据或者没有数据
	
	int mid = (l + r) >> 1;
	//1、递归方式来分区间 时间复杂度logn
	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);
	//2、双指针方法来挑数据。i指向数组开头l到mid为一个区间，j指向数组mid+1到r为另一个区间
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r) { //判断ij是否还在区间内以确保ij合法
		if (q[i] <= q[j]) temp[k++] = q[i++]; //因为归并排序稳定性的原因，所以最好当q[i] = q[j]时q[i]先到temp数组中
		else temp[k++] = q[j++];
	} //跳出循环的原因为，i或j其中一个已经指到了头，其中一个区间的数据已经比较完了，无法继续比较两个区间的数据
	while (i <= mid) temp[k++] = q[i++]; //此时情况为，j已经指到头，i还未指到头，所以要将i指向的区间的剩余部分依次放到temp数组中
	while (j <= r) temp[k++] = q[j++];   //与上述相反

	for (i = l, j = 0; i <= r; i++, j++) q[i] = temp[j]; //再将temp数组中的数据在放回q数组中，因为main函数中是输出q数组
}
int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &q[i]);

	merge_sort(q, 0, n - 1);

	for (int i = 0; i < n; i++) printf("%d ", q[i]);

	return 0;
}