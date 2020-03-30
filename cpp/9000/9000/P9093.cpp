#include<iostream>
#include<string>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 9093 단어 뒤집기
int main(){
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	while (t--) {
		getline(cin,s);
		string ts;
		for (int i = 0; i < s.length();i++) {
			if (s[i] == ' ') {
				reverse(ts.begin(), ts.end());
				cout << ts <<' ';
				ts = "";
			}
			else
				ts += s[i];
		}
		reverse(ts.begin(), ts.end());
		cout << ts << endl;
	}
}