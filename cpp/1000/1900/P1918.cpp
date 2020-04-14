#include<iostream>
#include<string>
#include<stack>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 1918 후위 표기식
int ll[200];
int main(){
	string s;
	stack<char>ss;
	queue<char>answer;
	ll['-'] = 2;
	ll['+'] = 2;
	ll['/'] = 3;
	ll['*'] = 3;
	ll['('] = 4;
	ll[')'] = 1;
	cin >> s;
	for (char a : s) {
		if (ll[a]==0) {
			answer.push(a);
		}
		else {
			if (ss.empty())
				ss.push(a);
			else {
				if (ll[a]==1) {
					while (ll[ss.top()] != 4) {
						answer.push(ss.top()); 
						ss.pop();
					}
					ss.pop();
				}
				else if(ll[ss.top()]>=ll[a]){
					while (!ss.empty()&&ll[ss.top()]>=ll[a]&&ll[ss.top()]!=4) {
						answer.push(ss.top()); ss.pop();
					}
					ss.push(a);
				}
				else {
					ss.push(a);
				}
			}
		}
	}
	while (!ss.empty()) {
		answer.push(ss.top()); ss.pop();
	}
	while (!answer.empty()) {
		cout << answer.front();
		answer.pop();
	}
}