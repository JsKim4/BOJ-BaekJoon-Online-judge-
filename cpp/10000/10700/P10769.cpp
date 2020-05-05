#include<iostream>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 10769 행복한지 슬픈지
int main(){
	string s;
	getline(cin,s);
	int h = 0, uh = 0;
	for (int i = 0; i < s.length() - 2;i++) {
		if (s[i] == ':'&&s[i+1]=='-') {
			if (s[i + 2] ==')'){
				h++;
			}
			else if (s[i + 2] == '(') {
				uh++;
			}
		}
	}
	if (!h && !uh) {
		cout << "none";
	}
	else if (h==uh) {
		cout << "unsure";
	}
	else
		cout << (h > uh ? "happy" : "sad");
}