#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define maxnum 100000000
int a[310];
int dp[310][310] = { 0 }, s[310][310];
void chain(int a[], int n);
void paint(int i, int j);
int main()
{
	int i, n;
	while ((scanf("%d", &n)) != EOF)
	{
		for (i = 0; i <= n; i++)
			scanf("%d", &a[i]);  //矩阵Ai的行列为A[i-1][i]
		chain(a, n);
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
