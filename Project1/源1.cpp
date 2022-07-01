#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <sstream>
#include <cstring> 
#define maxnum 100000000
using namespace std;

int a[310];
int dp[310][310] = { 0 }, s[310][310];
void chain(int a[], int n);
void paint(int i, int j);
int main()
{
	int i, n;
	SetConsoleOutputCP(CP_UTF8);
	printf("第一行请输入一个整数n，表示矩阵链的长度（1<=n<=300），第二行请输入n+1个数表示这些矩阵的行数和列数\n");
	while ((scanf("%d", &n)) != EOF)
	{
		for (i = 0; i <= n; i++)
			scanf("%d", &a[i]);  //矩阵Ai的行列为A[i-1][i]
		chain(a, n);
		printf("计算次数为：" );
		printf("%d\n", dp[1][n]);
		paint(1, n);
		printf("\n");
	}
}
void chain(int a[], int n)
{
	int i, j, l, k, temp;
	for (l = 1; l <= n - 1; l++)
	{
		for (i = 1; i <= n - l; i++)
		{
			j = i + l;
			dp[i][j] = maxnum;
			for (k = i; k <= j - 1; k++)
			{
				temp = dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j];
				ostringstream o;
				o << "M(" << i << "," << j << ")" << "=" << "M(" << i << "," << k << ")+M(" << k + 1 << "," << j << ")+P" << i - 1 << "*P" << k << "*P" << j;
				cout << o.str() << endl;
				ostringstream oss;
				oss  << temp << "="<< dp[i][k]<<"+"<< dp[k + 1][j]<<"+"<< a[i - 1] * a[k] * a[j];
				cout << oss.str() << endl;
	
				if (temp <= dp[i][j])
				{//这里的等于体现了左边优先
					dp[i][j] = temp;
					s[i][j] = k;
				}
			}
		}
	}
}
void paint(int i, int j)
{
	if (i == j)  printf("A%d", i);
	else
	{
		printf("(");
		paint(i, s[i][j]);
		paint(s[i][j] + 1, j);
		printf(")");
	}
}
