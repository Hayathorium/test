/*
 *integral of \prod_{i=0}^{m}\sin(b_i x)\prod_{i=m+1}^{n}\cos(b_i x)
 *through -PI~PI
*/
#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const int N = /*define n*/;
const int M = /*define m*/;
int b[N + 1] = {/*input a sequence*/ };
//integrand
long double func(long double x)
{
	long double product = 1;
	for (int i = 0; i <= M; i++)
	{
		product *= sin(b[i] * x);
	}
	for (int i = M+1; i <= N; i++)
	{
		product *= cos(b[i] * x);
	}
	return product;
}
//simpson's rule
long double integral(long double a, long double b, int n)
{
	long double step = (b - a) / n;
	long double area = 0.0;
	long double y = 0;
	for (int i = 0; i <= n; i++)
	{
		y = func(a + i * step);
		if (i == 0 || i == n)
		{
			area += y;
		} else if (i%2 == 1)
		{
			area += 4 * y;
		} else
		{
			area += 2 * y;
		}
	}
	return (area * step) / 3.0;
}
int main()
{
	long double low_end = -M_PI;
	long double high_end = M_PI;
	int steps = 1000000;
	cout << fixed;
	cout << setprecision(9);
	cout << integral(low_end, high_end, steps);
	return 0;
}
