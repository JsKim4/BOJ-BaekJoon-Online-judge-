#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 13567 로봇
int way[][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int main(){
	int n, m;
	cin >> n >> m;
	int y = 0, x = 0,w=0;
	bool tf = true;
	while (m--) {
		string s; int a;
		cin >> s >> a;
		if (s == "MOVE") {
			int wy = y + way[w][0] * a;
			int wx = x + way[w][1] * a;
			if (wy >= 0 && wy < n && wx >= 0 && wx < n) {
				y = wy;
				x = wx;
			}
			else {
				tf = false;
			}
		}
		else {
			w += a?-1:1;
			w += 4;
			w %= 4;
		}
	}
	if (tf)
		cout << x << " " << y << endl;
	else
		cout << -1;
}