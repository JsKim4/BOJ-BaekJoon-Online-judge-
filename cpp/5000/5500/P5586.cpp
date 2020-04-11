#include<iostream>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 5586 JOI와 IOI
int main(){
	string s;
	cin >> s;
	int joi=0, ioi=0;
	for (int i = 0; i < s.length() - 2;i++) {
		if (s[i + 1] == 'O'&&s[i+2]=='I') {
			if (s[i] == 'J')
				joi++;
			else if (s[i] == 'I')
				ioi++;
		}
	}
	cout << joi << "\n" << ioi;
}