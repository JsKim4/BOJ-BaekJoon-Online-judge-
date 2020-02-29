#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 10101 삼각형 외우기
int main() {
	int a, b, c; cin >> a >> b >> c;
	if ((a + b + c) != 180)
		cout << "Error";
	else 
		if (a == b && a == c)
			cout << "Equilateral";
		else if (a == b || b == c || a == c)
			cout << "Isosceles";
		else
			cout << "Scalene";

}