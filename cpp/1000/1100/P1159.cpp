#include<iostream>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 1159 농구 경기
int alpha[26];
int main(){
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		alpha[s[0] - 'a']++;
	}
	bool tf = true;
	for (int i = 0; i < 26;i++) {
		if (alpha[i] >= 5) {
			tf = false;
			cout << (char)(i + 'a');
		}
	}
	if (tf)
		cout << "PREDAJA";
}