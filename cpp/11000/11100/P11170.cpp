#include<iostream>
#include<cmath>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 11170 0의 개수
int arr[1000001] = {1};
int main(){
	for (int i = 1; i <= 1000000;i++) {
		int j;
		for (j = 0; pow(10, j) <= i; j++);
		int cnt = 0;
		for (int l = 0; l < j;l++) {
			int num = (i % (int)pow(10, l + 1)) / (int)pow(10, l);
			if (!num)
				cnt++;
		}
		arr[i] = arr[i - 1] + cnt;
	}
	int t;
	cin >>t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a == 0) {
			cout << arr[b]<<endl;
		}else{
			cout << arr[b] - arr[a - 1] << endl;
		}
	}
}