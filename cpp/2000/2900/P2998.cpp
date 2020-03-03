#include<iostream>
#include<cstring>
#include<stack>
#pragma warning (disable:4996)
using namespace std;
// 2998 8진수
char s[101];
int main(){
	int i;
	stack<int>st;
	cin >> s;
	for (i = strlen(s) - 1; i > 1;i-=3) {
		int a = s[i] - '0', b = (s[i - 1] - '0') * 2, c = (s[i - 2] - '0') * 4;
		int n = a + b + c;
		st.push(n);
	}
	if (i == 1) {
		int a = s[i] - '0', b = (s[i - 1] - '0') * 2;
		st.push(a + b);
	}
	else if(i==0){
		st.push(1);
	}
	while (!st.empty()) {
		int n = st.top(); st.pop();
		cout << n;
	}
}
