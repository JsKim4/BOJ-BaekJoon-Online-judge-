#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 2530 인공지능 시계
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	c += d; b += c / 60; a += b / 60;
	cout << a % 24 << " " << b % 60 << " " << c % 60;
}