#include<iostream>
#include<string>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 13413 오셀로 재배치
int main(){
	int T;
	scanf("%d",&T);
	while (T--) {
		int a;
		string s1, s2;
		scanf("%d", &a);
		cin >> s1 >> s2;
		int b=0, w=0;
		for (int i = 0; i < a;i++) {
			if (s1[i] != s2[i]) {
				if (s1[i] == 'B')
					b++;
				else
					w++;
			}
		}
		printf("%d\n", b + w - min(b, w));
	}
}