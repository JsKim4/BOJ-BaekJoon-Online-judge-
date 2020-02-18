#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 4153 직각삼각형
int main(){
	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (a == 0&&b ==0&& c == 0)
			return 0;
		if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
			cout << "right\n";
		else
			cout << "wrong\n";
	}
}