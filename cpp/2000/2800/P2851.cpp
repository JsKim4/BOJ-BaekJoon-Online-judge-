#include<iostream>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;
// 2851 슈퍼 마리오
int n, i = 10;
int main(){
	int s = 0;
	int m = 0;
	while (--i != -1) {
		cin >> n;
		s += n;
		if (abs(100 - s) <= abs(100 - m))
			m = s;
	}
	cout << m;
}