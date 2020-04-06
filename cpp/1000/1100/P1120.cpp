#include<iostream>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 1120 문자열
string a, b;
int main(){
	cin >> a >> b;
	int mmin = 999;
	for (int i = 0; i <= b.length() - a.length(); i++) {
		int cnt = 0;
		for (int j = 0; j < a.length();j++) {
			if (a[j] != b[j+i])
				cnt++;
		}
		if (cnt < mmin)
			mmin = cnt;
	}
	cout << mmin;
}