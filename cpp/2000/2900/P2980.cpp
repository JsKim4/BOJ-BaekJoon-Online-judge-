#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2980 도로와 신호등
int L[1001][2];
int n, l;
int main(){
	cin >> n >> l;
	while (n--) {
		int d, r, g;
		cin >> d >> r >> g;
		L[d][0] = r;
		L[d][1] = g;
	}
	int t = 0;
	int loc = 0;
	while (loc!=l) {
		//cout << loc << " " << t << endl;
		if (L[loc][0]==0) {
			t++;
			loc++;
			continue;
		}
		int d_time = t % (L[loc][0] + L[loc][1]);
		if (d_time< L[loc][0]) {
			t += (L[loc][0]-d_time+1);
			loc++;
		}
		else {
			t++;
			loc++;
		}
	}
	cout << t << endl;
}