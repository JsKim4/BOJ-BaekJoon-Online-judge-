#include<iostream>
#include<stack>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 1935 후위 표기식2
int n[26];
int x;
stack<double>st;
int main(){
	string s;
	cin >> x;
	cin >> s;

	for (int i = 0; i < x;i++) {
		cin >> n[i];
	}
	for (int i = 0; i < s.length();i++) {
		if(s[i]>='A'&&s[i]<='Z')
			st.push(n[s[i]-'A']);
		else {
			double a = st.top(); st.pop();
			double b = st.top(); st.pop();
			switch (s[i]) {
			case '*':
				st.push(b * a);
				break;
			case '+':
				st.push(b + a);
				break;
			case '/':
				st.push(b / a);
				break;
			case '-':
				st.push(b - a);
				break;
			}
		}
	}
	printf("%.2lf", st.top());
}