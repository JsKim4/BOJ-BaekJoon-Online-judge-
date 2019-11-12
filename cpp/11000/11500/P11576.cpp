#include <iostream>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
long long bi[31][100];
int biM[31] = { 21,21,22,15,15,15,14,14,14,14,14,14,12,12,12,12,12,12,11,11,11,11,11,11,11,11,11,11,11,11,11 };
int main()
{
	for (int i = 1; i < 31; i++) {
		bi[i][0] = 1;
	}

	for (int i = 1; i < 31; i++) {
		long long n = 1;
		for (int j = 0; j < biM[i]; j++) {
			bi[i][j] = n;
			n *= i;
		}
	}
	long long numt = 0;
	int A, B, m;
	scanf("%d %d", &A, &B);
	scanf("%d", &m);
	int temp;
	for (int i = m - 1; i >= 0; i--) {
		scanf("%d", &temp);
		numt += bi[A][i] * temp;
	}
	bool a = false;
	for (int i = biM[B] - 1; i >= 0; i--) {
		if (numt >= bi[B][i]) {
			printf("%lld ", numt / bi[B][i]);
			numt %= bi[B][i];
			a = true;
		}
		else if (a) {
			printf("0 ");
		}
	}

}