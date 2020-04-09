#include<iostream>
#include<stack>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 5397 키로거
int main(){
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		stack<char>st[2];
		for (int i = 0; i < s.length();i++) {
			if (s[i] == '<') {
				if (!st[0].empty()) {
					st[1].push(st[0].top());
					st[0].pop();
				}
			}
			else if (s[i] == '>') {
				if (!st[1].empty()) {
					st[0].push(st[1].top());
					st[1].pop();
				}
			}
			else if (s[i] == '-') {
				if (!st[0].empty()) 
					st[0].pop();
			}
			else {
				st[0].push(s[i]);
			}
		}
		while (!st[0].empty()) { st[1].push(st[0].top()); st[0].pop(); }
		while (!st[1].empty()) { printf("%c", st[1].top()); st[1].pop(); }
		printf("\n");
	}
}