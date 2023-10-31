/*
 *Calculate ((-1)^[(m+1)/2])(p+q)(2T_{e,m}(X_n)-T(X_n))/(2^n)
 *by directly calculating T and T_em
*/
#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
using namespace std;
const int N = /*define n*/;
const int M = /*define m*/;
int b[N+1] = {/*input a sequence*/};
int main()
{
    b[0] = 2;
	for (int i = 1; i < N+1; i++) {
		b[i] = (i % 4) ^ 2 + (i % 5);
	}
	int sum, pCount, T = 0, T_em = 0;
		for (int k = 0; k < pow(2, N); k++)
		{
		    pCount = 0;
			sum = 0;
			for (int l = 0; l < N; l++)
			{
				if ((k >> l) & 1)
				{
					sum += b[N-l];
					if(N-l <= M)
                    {
                        pCount++;
                    }
				}
				else {
					sum -= b[N-l];
				}
			}
			if (sum == b[0])
			{
			    if(pCount%2==0)
                    T_em++;
				T++;
			}
		}
	cout << (pow(-1.0, (M+1)/2) / pow(2.0, N))*2*(2*T_em-T)*M_PI << endl;
	return 0;
}
