#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2869 달팽이는 올라가고 싶다
int main(){
	int d = 1;
	int a, b, v;
	cin >> a >> b >> v;
	v -= a;
	v = v > 0 ? v : 0;
	d += v / (a - b);
	v -= (a - b) * (d - 1);
	cout << d+(v>0);
}