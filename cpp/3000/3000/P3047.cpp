#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 3047 ABC
int main() {
	int n[3];
	int num[3];
	scanf("%d %d %d", &n[0], &n[1], &n[2]);
	num[0] = n[0] < n[1] ? n[0] < n[2] ? n[0] : n[2] : n[1] < n[2] ? n[1] : n[2];
	num[2] = n[0] < n[1] ? n[1] < n[2] ? n[2] : n[1] : n[0] < n[2] ? n[2] : n[0];
	num[1] = n[0] + n[1] + n[2] - num[0] - num[2];
	char abc[4];
	scanf("%s", &abc);
	for (int i = 0; i < 3;i++) {
		printf("%d ",num[abc[i]-'A']);
	}
}