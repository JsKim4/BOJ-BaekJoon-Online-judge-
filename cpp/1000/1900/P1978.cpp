#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1978 소수 찾기
bool s[1001] = {1,1,};
int main(){
	for (int i = 2; i < 33;i++) {
		if (s[i] == 0) {
			for (int j = i * 2; j <= 1000;j+=i) {
				s[j] = 1;
			}
		}
	}
	int n,answer = 0;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		if (s[a] == 0)
			answer++;
	}
	cout << answer;
}