#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 10987 모음의 개수
int main(){
	char s[101];
	int answer = 0;
	cin >> s;
	for (int i = 0; s[i] != 0;i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			answer++;
	}
	cout << answer;
}