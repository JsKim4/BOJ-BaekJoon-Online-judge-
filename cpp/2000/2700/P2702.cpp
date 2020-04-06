#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2702 초6 수학
int main(){
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int su = 0;
		for (int i = 1; i <= a;i++) {
			if (a % i == 0 && b % i == 0)
				su = i;
		}
		cout << a * b / su << " " << su << endl;
	}
}