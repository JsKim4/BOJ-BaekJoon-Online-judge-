#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 10610 30
int num[10];
int main() {
	char n[100001];
	scanf("%s", &n);
	int i = 0;
	while (n[i] != 0) {
		num[n[i++] - '0']++;
	}
	if (num[0] == 0)
		printf("-1");
	else {
		int sum = 0;
		for (int i = 0; i < 10;i++)
			sum += (num[i] * i);
		if (sum % 3 != 0)
			printf("-1");
		else {
			for (int i = 9; i >= 0; i--) {
				for (int j = 0; j < num[i];j++) {
					printf("%d",i);
				}
			}
		}
	}
}