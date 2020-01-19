#include<iostream>
#include <string>
#include <cstring>
#include<algorithm>
#include <vector>
#include <queue>
#include<cmath>
#include<stack>
#pragma warning(disable:4996)
using namespace std;
char a[10005];
char b[10005];
char temp[10010];
char t[10005];
int alen, blen;
// 15353 큰 수 A+B (2)
int main()
{
	scanf("%s %s", &a, &b);
	for (alen = 0; a[alen] != 0; alen++);
	for (blen = 0; b[blen] != 0; blen++);
	if (alen < blen)
	{
		strcpy(t, a);
		strcpy(a, b);
		strcpy(b, t);
		int q = alen;
		alen = blen;
		blen = q;
	}
	temp[alen--] = 0;
	blen--;
	while (alen > 0)
	{
		if (blen >= 0)
			temp[alen] += (a[alen] - '0' + b[blen]);
		else
			temp[alen] += a[alen];
		if (temp[alen] > '9')
		{
			temp[alen - 1] = (temp[alen] - '0') / 10;
			temp[alen] = (temp[alen] - '0') % 10 + '0';
		}
		//printf("%d %d %c\n",alen,blen,temp[alen]);
		alen--;
		blen--;
	}
	for (alen = 0; a[alen] != 0; alen++);
	temp[0] += a[0];
	if (blen == 0)
	{
		temp[0] += b[0] - '0';
	}
	if (temp[0] > '9')
	{
		printf("%c", (temp[0] - '0') / 10 + '0');
	}
	printf("%c", (temp[0] - '0') % 10 + '0');

	for (int i = 1; i < alen; i++)
	{
		printf("%c", temp[i]);
	}
}