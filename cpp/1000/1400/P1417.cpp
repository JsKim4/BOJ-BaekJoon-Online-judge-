#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1417 국회의원 선거
int n;
int h[1001];
int main(){
	cin >> n; int answer = 0;
	int d,s;
	cin >> s;
	for (int i = 1; i < n;i++) {
		cin >> d;
		h[d]++;
	}
	for (int i = 1000; i > 0;i--) {
		if (i < s) {
			break;
		}
		if (h[i] > 0) {
			s++; answer++;
			h[i]--; h[i - 1]++;
			i++;
		}
	}

	cout << answer;
}