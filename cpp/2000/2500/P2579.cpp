#include<iostream>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 2579 계단 오르기
int n;
int arr[310];
int answer[310][2];
void dp(int i) {
	if (i >= n) {
		return;
	}
	answer[i][0] = max(answer[i - 2][0], answer[i - 2][1])+arr[i];
	answer[i][1] = answer[i - 1][0] + arr[i];
	dp(i + 1);
}
int main(){
	cin >> n;
	for (int i = 0; i < n;i++) 
		cin >> arr[i];
	answer[0][0] = arr[0];
	answer[1][0] = arr[1];
	answer[1][1] = arr[1] + arr[0];
	dp(2);
	cout << max(answer[n - 1][0], answer[n - 1][1]);
}