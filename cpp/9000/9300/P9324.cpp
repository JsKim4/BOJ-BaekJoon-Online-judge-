#include<iostream>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 9324 진짜 메시지
int main(){
	int T;
	scanf("%d",&T);
	while (T--) {
		int alpha[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		string s;
		cin >> s;
		int now = -1;
		bool bf = false;
		for (int i = 0; i < s.length();i++) {
			if (now != -1) {
				if (s[i] - 'A' != now) {
					bf = true;
					break;
				}
				now = -1;;
			}
			else {
				alpha[s[i] - 'A']++;
				if (alpha[s[i] - 'A'] == 3) {
					now = s[i] - 'A';
					alpha[s[i] - 'A'] = 1;
				}
			}
		}
		if (bf||now!=-1) {
			printf("FAKE\n");
		}
		else {
			printf("OK\n");
		}
	}
}