#include<iostream>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 1316 그룹 단위 체커
bool alpha[26];
void init() {
	for (int i = 0; i < 26;i++) 
		alpha[i] = false;
}
int main(){
	int t, answer = 0;
	cin >> t;
	while (t--) {
		init();
		string s;
		cin >> s;
		bool tn = true;
		for (int i = 0; i < s.length();i++) {
			if (alpha[s[i] - 'a'] == false)
				alpha[s[i] - 'a'] = true;
			else if (s[i] == s[i - 1]) {
				continue;
			}
			else {
				tn = false;
				break;
			}
		}
		if (tn)
			answer++;
	}
	cout << answer;
}