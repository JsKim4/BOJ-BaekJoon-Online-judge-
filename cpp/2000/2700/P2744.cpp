#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2744 대소문자 바꾸기
char s[101];
int main() {
	cin >> s;
	for (int i = 0; s[i] != 0; i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			cout << (char)(s[i] - 'a' + 'A');
		else
			cout << (char)(s[i] - 'A' + 'a');
	}
}