#include<iostream>
#include<stack>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 3986 좋은 단어
int main(){
	int n;
	cin >> n;
	string s;
	int answer = 0;
	while (n--) {
		stack<char>st;
		cin >> s;
		for (int i = 0; i < s.length();i++) {
			if (st.empty()) {
				st.push(s[i]);
			}
			else {
				if (s[i] == st.top()) {
					st.pop();
				}
				else
					st.push(s[i]);
			}
		}
		if (!st.size())
			answer++;
	}
	cout << answer;
}