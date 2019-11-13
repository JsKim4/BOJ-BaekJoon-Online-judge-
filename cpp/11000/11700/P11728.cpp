#include<iostream>
#pragma warning (disable:4996)
using namespace std;

int nArray[1000000];
int mArray[1000000];
int main() {
	int n, m;
	scanf("%d %d",&n,&m);
	int k = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &nArray[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &mArray[i]);
	}
	int in = 0, im = 0;
	for (k = 0; in != n && im != m; k++) {
		if (nArray[in] > mArray[im])
			printf("%d\n",mArray[im++]);
		else
			printf("%d\n", nArray[in++]);
	}
	if (in == n) {
		for (; k < n + m; k++) {
			printf("%d\n", mArray[im++]);
		}
	}
	else {
		for (; k < n + m; k++) {
			printf("%d\n", nArray[in++]);
		}
	}
}
