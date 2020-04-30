#include<iostream>
#include<algorithm>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;
// 2607 비슷한 단어
int alpha[26];
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < s.length();i++) {
		alpha[s[i] - 'A']++;
	}
	n--;
	int answer = 0;
	while (n--) {
		string ss;
		cin >> ss;
		int alp[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		for (int i = 0; i < ss.length(); i++) {
			alp[ss[i] - 'A']++;
		}
		int cnt = 0;
		for (int i = 0; i < 26;i++) {
			cnt += abs(alp[i] - alpha[i]);
		}
		if (cnt <= 1) {
			answer++;
		}
		else if (ss.length() == s.length() && cnt == 2)
			answer++;
	}
	cout << answer;
}