#include<iostream>
#include<deque>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 1213 팰린드롬 만들기
int alpha[26];
int main() {
	char input[51];
	deque<char>a;
	char aa = 0;

	cin >> input;
	for (int i = 0; input[i] != 0;i++) 
		alpha[input[i] - 'A']++;
	for (int i = 25; i >= 0;i--) {
		if (alpha[i] % 2 != 0) {
			if (aa==0) {
				alpha[i]--;
				aa=i+'A';
			}
			else {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
		}
		for (int j = 0; j < alpha[i];j+=2) {
			a.push_back(i + 'A');
			a.push_front(i + 'A');
		}
	}
	if (a.size() == 0 && aa != 0)
		cout << aa;
	for (int i = 0; i < a.size();i++) {
		if (i == a.size() / 2 && aa != 0)
			cout << aa;
		cout << a[i];
	}


}