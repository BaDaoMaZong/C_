//#define _CRT_SECURE_NO_WARNINGS //���������⣬��Ϊ����д��scanf������������ϲ�����ȫ
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
//	if (l >= r) return; //������ֻ��һ�����ݻ���û�����ݣ�ֱ�ӷ���
//
//	int x = q[(l + r) >> 1], i = l - 1, j = r + 1; //x���ȡ�е㣬�ܱ������������ͨ����
//	while (i < j) {
//		do i++; while (q[i] < x); //��Ϊ�������߶�ʮһ����i��j�ȶ�������������Ҫi = l - 1��j = r + 1�������Ϳ��Կ�ʼiָ����߽磬rָ���б߽�
//		do j--; while (q[j] > x);
//		if (i < j) swap(q[i], q[j]); //���iָ������ݴ���jָ������ݣ���i��j��û������������Ҫ����ij��ָ�������
//	}
//
//	quick_sort(q, l, j);		//����quick_sort(q, l, i - 1)
//	quick_sort(q, j + 1, r);    //����quick_sort(q, i, r)
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