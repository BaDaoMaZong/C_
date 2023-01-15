/*题目：
给定一个浮点数 n，求它的三次方根。

输入格式
共一行，包含一个浮点数 n。

输出格式
共一行，包含一个浮点数，表示问题的解。

注意，结果保留 6位小数。

数据范围
−10000≤n≤10000
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	double l = -10000, r = 10000; //要根据数据范围自行判断最终答案在那个区间里面，需要自己来控制区间的大小

	double n;
	scanf("%lf", &n); //double对应%lf，int对应%d

	while (r - l > 1e-8) { //若答案要保留6位小数则要写1e-8，若保留4位小数则要写1e-6，总是要比题目大2

		double mid = (l + r) / 2;
		if (mid * mid * mid >= n) r = mid; //if里面的判断本质是mid与n三次根号下的数去比，若大于则mid在n的三次根下的数的右边，反之则在左边。
		else l = mid; //浮点数二分不用考虑边界问题
	
	}
	printf("%.6lf", l);
	return 0;
}