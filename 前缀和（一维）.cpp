/*��Ŀ��
����һ������Ϊ n���������С�
������������ m��ѯ�ʣ�ÿ��ѯ������һ�� l,r��
����ÿ��ѯ�ʣ����ԭ�����дӵ� l�������� r�����ĺ͡�

�����ʽ
��һ�а����������� n�� m��
�ڶ��а��� n����������ʾ�������С�
������ m�У�ÿ�а����������� l�� r����ʾһ��ѯ�ʵ����䷶Χ��

�����ʽ
�� m�У�ÿ�����һ��ѯ�ʵĽ����
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

const int N = 100010;

int q[N], s[N]; //һάǰ׺����Ҫ��������

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) scanf("%d", &q[i]);

	s[0] = 0; //��ǰ׺�������±�Ϊ0��λ�ó�ʼ��Ϊ0
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + q[i]; //һάǰ׺�͹�ʽ��s[i] = s[i-1] + a[i]

	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);

		printf("%d\n", s[r] - s[l - 1]); //������l��r�ĺͣ�
	}
	return 0;
}