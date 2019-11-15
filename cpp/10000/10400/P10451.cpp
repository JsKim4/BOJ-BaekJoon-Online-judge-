#include<iostream>
#pragma warning (disable:4996)
using namespace std;
int list[1001];
// 10451
bool check(int startNum,int nowN) {
	if (list[nowN]==0) {
		return false;
	}
	int num = list[nowN];
	list[nowN] = 0;
	if (startNum == num) {
		return true;
	}else {
		return check(startNum,num);
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &list[i]);
		}
		int count = 0;
		for (int i = 1; i <= n; i++) {
			if (check(i, i)) {
				count++;
			}
		}
		printf("%d\n", count);
	}

}