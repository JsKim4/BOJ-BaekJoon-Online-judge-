#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 9935 문자열 폭발
int lenArr[36];
int main(){
	string s,b;
	stack<char>st;
	stack<char>tmp;
	cin >> s >> b;
	while (!s.empty()) {
		tmp.push(s.back());
		s.pop_back();
	}
	int len = 0;
	while (!tmp.empty()) {
		//cout << tmp.top() << " " << b[len] << endl;
		if (tmp.top() == b[len]) {
			len++;
		}
		else {
			len = 0;
			if (tmp.top() == b[len])
				continue;
		}
		st.push(tmp.top()); tmp.pop();
		if (len == b.length()) {
			while (len--) {
				st.pop();
			}
			for (int i = 0; i < b.length() && !st.empty();i++) {
				tmp.push(st.top()); st.pop();
			}
			len = 0;
		}
	}
	if (st.empty()) {
		cout << "FRULA";
		return 0;
	}
	while (!st.empty()) {
		s.push_back(st.top()); st.pop();
	}
	reverse(s.begin(), s.end());
	cout << s;

}