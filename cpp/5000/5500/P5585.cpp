#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 5585 °Å½º¸§µ·
static const int M[6] = {500,100,50,10,5,1};
int main() {
	int n, r = 0;
	scanf("%d", &n);
	n = 1000 - n;
	for (int i = 0; i < 6;i++) {
		r += n / M[i];
		n %= M[i];
	}
	printf("%d",r);
}