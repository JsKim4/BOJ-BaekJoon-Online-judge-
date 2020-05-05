#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 3943 헤일스톤 수열
int main(){
	int t;
	scanf("%d",&t);
	while (t--) {
		int num;
		scanf("%d", &num);
		int m = num;
		while (num != 1) {
			if (num % 2 == 0) {
				num /= 2;
			}
			else {
				num = num * 3 + 1;
			}
			if (m < num) {
				m = num;
			}
		}
		printf("%d\n",m);
	}
}