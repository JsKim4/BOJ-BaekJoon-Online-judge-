#include<iostream>
#include<string>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 9933 민균이의 비밀번호
int main(){
	int n;
	cin >> n;
	string ss[100];
	for (int i = 0; i < n;i++) {
		cin >> ss[i];
	}
	for (int i = 0; i < n;i++) {
		bool tf = false;
		reverse(ss[i].begin(), ss[i].end());
		string rs = ss[i];
		reverse(ss[i].begin(), ss[i].end());
		for (int j = 0; j <= i;j++) {
			if (rs == ss[j]) {
				cout <<rs.length()<<" " <<rs[rs.length()/2]<<endl;
				return 0;
			}
		}
	}
}