#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1308 D-Day
int m[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int main() {
	int y[6];
	for (int i = 0; i < 6; i++)
		cin >> y[i];
	//cout << y[0] - y[3] << " " << y[1] - y[4] << " " << y[2] - y[5] << endl;
	if (y[3] - y[0] > 1000 || (y[3] - y[0] == 1000 && y[4] - y[1] > 0) || (y[3] - y[0] == 1000 && y[4] - y[1] == 0 && y[5] - y[2] >= 0)) {
		cout << "gg";
		return 0;
	}
	int count = 0;
	while (true) {
		if (y[0] == y[3] && y[1] == y[4] && y[2] == y[5])
			break;
		y[2]++;
		int md = m[y[1]] + (y[1] == 2 && ((y[0] % 4 == 0 && y[0] % 100 != 0) || y[0] % 400 == 0));
		if (y[2] > md) {
			y[1]++;
			y[2] -= md;
		}
		if (y[1] > 12) {
			y[0]++;
			y[1] = 1;
		}
		//cout << y[2] << " " << y[1] << " " << y[0] << endl;
		count++;
	}
	cout <<"D-"<< count;
}