#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1439 뒤집기
char s[1000001];
int main(){
	int o=0, z=0;
	cin >> s;
	for (int i = 1; i < 1000001;i++) {
		if (s[i] != s[i - 1]) {
			if (s[i - 1] == '0')
				o++;
			else
				z++;
		}
	}
	cout << (o > z ? z : o);
}