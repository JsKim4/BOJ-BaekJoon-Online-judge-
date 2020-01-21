#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1264 모음의 개수
int main() {
	int m=0;
	while (true) {
		char a;
		scanf("%1c",&a);
		if (a == '\n') {
			printf("%d\n",m);
			m = 0;
		}
		if (a == '#' && m == 0)
			return 0;
		if (a == 'e' || a == 'a' || a == 'i' || a == 'o' || a == 'u' || a == 'E' || a == 'A' || a == 'I' || a == 'O' || a == 'U') {
			m++;
		}
	}
}