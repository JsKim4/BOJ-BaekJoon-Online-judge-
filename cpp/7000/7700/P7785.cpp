#include<iostream>
#include<queue>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 7785 회사에 있는 사람
int main(){
	int n;
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	priority_queue<string>enter;
	priority_queue<string>leave;
	cin >> n;
	while (n--) {
		string a, b;
		cin >> a >> b;
		if (!b.compare("enter")) 
			enter.push(a);
		else
			leave.push(a);
	}
	while (!enter.empty()) {
		string e ,l = "";
		e = enter.top();
		enter.pop();
		if (!leave.empty()) {
			l = leave.top(); 
		}
		if (!l.compare(e)) {
			leave.pop();
		}
		else {
			cout << e << "\n";
		}

	}

}