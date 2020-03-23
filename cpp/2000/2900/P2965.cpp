#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2965 캥거루 세마리
int main(){
	int a, b, c;
	cin >> a >> b >> c;
	cout << ((b - a) > (c - b) ? (b - a) - 1 : (c - b) - 1);
}