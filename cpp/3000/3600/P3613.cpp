#include<iostream>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 3613 Java vs C++
int main(){
	string s;
	int jc=0;
	cin >> s;
	for (int i = 0; i < s.length();i++) {

		if(s[i]=='_'){
			if (i > 0 && s[i - 1] == '_') {
				jc = -1;
				break;
			}
			if (jc == 2) {
				jc = -1;
				break;
			}
			jc = 1;
		}
		if (s[i] >= 'A' && s[i] <= 'Z'){
			if (jc==1) {
				jc = -1;
				break;
			}
			jc = 2;
		}
	}
	if (s[s.length() - 1] == '_'||(s[0]>='A'&&s[0]<='Z')||s[0]=='_')
		jc = -1;
	if (jc == -1) {
		cout << "Error!";
	}
	else if (jc == 0) {
		cout << s;
	}
	else if (jc == 1) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '_') {
				cout << (char)(s[++i] - 'a' + 'A');
			}
			else
				cout << (char)s[i];
		}
	}
	else if (jc == 2) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				cout << "_" << (char)(s[i] - 'A' + 'a');
			}
			else
				cout << (char)s[i];
		}
	}
}