#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 6359 만취한 상범
bool room[101] = {0,0};
int answer[101];
int main(){
	int T;
	for (int i = 2; i <= 100;i++) 
		for (int j = i; j <= 100; j += i)
			room[j] = !room[j];
	int ans = 0;
	for (int i = 1; i <= 100;i++) {
		if (!room[i])
			ans++;
		answer[i] = ans;
	}
	cin >> T;
	while (T--) {
		int a;
		scanf("%d", &a);
		printf("%d\n", answer[a]);
	}
}