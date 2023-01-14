//#define _CRT_SECURE_NO_WARNINGS //编译器问题，因为下面写的scanf在这个编译器上并不安全
//
//#include <iostream>
//
//using namespace std;
//
//const int N = 100010;
//int q[N];
//
//void quick_sort(int q[], int l, int r) {
//
//	if (l >= r) return; //数组中只有一个数据或者没有数据，直接返回
//
//	int x = q[(l + r) >> 1], i = l - 1, j = r + 1; //x最好取中点，能避免特殊情况不通过，
//	while (i < j) {
//		do i++; while (q[i] < x); //因为不管三七二十一都是i，j先动，所以上面需要i = l - 1，j = r + 1，这样就可以开始i指向左边界，r指向有边界
//		do j--; while (q[j] > x);
//		if (i < j) swap(q[i], q[j]); //如果i指向的数据大于j指向的数据，且i，j还没遇见，我们需要交换ij所指向的数据
//	}
//
//	quick_sort(q, l, j);		//或者quick_sort(q, l, i - 1)
//	quick_sort(q, j + 1, r);    //或者quick_sort(q, i, r)
//}
//int main() {
//
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) scanf("%d", &q[i]);
//
//	quick_sort(q, 0, n - 1);
//
//	for (int i = 0; i < n; i++) printf("%d ", q[i]);
//
//	return 0;
//}