#include<iostream>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
// 1342 행운의 문자열
int nm[10];
int now = 0b0000000000;
int nnn[] = { 0b0000000001 ,0b0000000010 ,0b0000000100 ,0b0000001000 ,0b0000010000 ,0b0000100000 ,0b0001000000 ,0b0010000000,0b0100000000,0b1000000000 };
int mmm[] = { 0b1111111110 ,0b1111111101 ,0b1111111011 ,0b1111110111 ,0b1111101111 ,0b1111011111 ,0b1110111111 ,0b1101111111,0b1011111111,0b0111111111 };
char s[11];
int answer = 0;
vector<string>v;
void solve(int i, int n, int m) {
	if (i == n) {
		string str="";
		for (int x = 0; x < n-1; x++) {
			if (s[nm[x]]==s[nm[x+1]]) {
				return;
			}
		}
		v.push_back(str);
	}
	for (int j = 0; j < m; j++) {
		answer++;
		if ((now & nnn[j]) == 0) {
			nm[i] = j;
			if (i>0&&s[nm[i]]!=s[nm[i-1]]) {
				now |= nnn[j];
				solve(i + 1, n, m);
				now &= mmm[j];
			}
		}
	}
}
int main() {
	cin >> s; 
	for (int n = 0; n < 11;n++) {
		if (s[n] == 0) {
			solve(0,n,n);
			break;
		}
	}
	cout << answer;
}