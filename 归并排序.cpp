#define _CRT_SECURE_NO_WARNINGS //���������⣬�����scanf�ڴ˱������ϲ�����ȫ

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int q[N], temp[N];

void merge_sort(int q[], int l, int r) {

	if (l >= r) return; //ֻ��һ�����ݻ���û������
	
	int mid = (l + r) >> 1;
	//1���ݹ鷽ʽ�������� ʱ�临�Ӷ�logn
	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);
	//2��˫ָ�뷽���������ݡ�iָ�����鿪ͷl��midΪһ�����䣬jָ������mid+1��rΪ��һ������
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r) { //�ж�ij�Ƿ�����������ȷ��ij�Ϸ�
		if (q[i] <= q[j]) temp[k++] = q[i++]; //��Ϊ�鲢�����ȶ��Ե�ԭ��������õ�q[i] = q[j]ʱq[i]�ȵ�temp������
		else temp[k++] = q[j++];
	} //����ѭ����ԭ��Ϊ��i��j����һ���Ѿ�ָ����ͷ������һ������������Ѿ��Ƚ����ˣ��޷������Ƚ��������������
	while (i <= mid) temp[k++] = q[i++]; //��ʱ���Ϊ��j�Ѿ�ָ��ͷ��i��δָ��ͷ������Ҫ��iָ��������ʣ�ಿ�����ηŵ�temp������
	while (j <= r) temp[k++] = q[j++];   //�������෴

	for (i = l, j = 0; i <= r; i++, j++) q[i] = temp[j]; //�ٽ�temp�����е������ڷŻ�q�����У���Ϊmain�����������q����
}
int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &q[i]);

	merge_sort(q, 0, n - 1);

	for (int i = 0; i < n; i++) printf("%d ", q[i]);

	return 0;
}