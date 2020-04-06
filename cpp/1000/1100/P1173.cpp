#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1173 운동
int main(){
	int N, m, M, T, R;
	cin >> N >> m >> M >> T >> R;
	if ((M - m) < T) {
		cout << -1;
		return 0;
	}
	int now = m;
	int t = 0;
	while (N != 0) {
		if (now + T <= M) {
			now += T;
			N--;
		}
		else {
			now -= R;
			if (now <= m)
				now = m;
		}
		t++;
	}
	cout << t;
}