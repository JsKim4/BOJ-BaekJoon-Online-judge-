#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 13460 구슬탈출2
int order_w[10];
int k = 0;
void order_list(int i) {
	if (i == 10) {
		for (int i = 0; i < 10;i++) {
			printf("%d ",order_w[i]);
		}
		printf("\n");
		k++;
		return;
	}
	for (int w = 0; w < 4;w++) {
		if (i!=0&&w == order_w[i - 1])
			continue;
		order_w[i] = w;
		order_list(i + 1);
	}
}
int main(){
	order_list(0);
	cout << k;
}