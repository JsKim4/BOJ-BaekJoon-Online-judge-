#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2884 알람시계
int main(){
	int h, m;
	scanf("%d %d",&h,&m);
	m -= 45;
	if (m < 0) {
		h -= 1;
		m += 60;
		if (h < 0) {
			h += 24;
		}
	}
	printf("%d %d",h,m);
}