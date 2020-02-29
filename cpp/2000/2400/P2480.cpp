#include<iostream>

#pragma warning (disable:4996)
using namespace std;
// 2480 주사위 세개
int max(int a, int b) { return a > b ? a : b; }
int main(){
	int a, b, c;
	cin >> a >> b >> c;
	cout << ((a == b &&a==c)? a * 1000 + 10000 : (a == b) ? a * 100 + 1000 : (a == c) ? a * 100 + 1000 : (c == b) ? b * 100 + 1000 : max(a, max(b, c))*100);

}