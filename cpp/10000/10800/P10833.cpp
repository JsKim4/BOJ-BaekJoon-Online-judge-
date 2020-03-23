#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 10833 사과
int main(){
	int n;
	int sum = 0;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		sum += b% a;
	}
	cout << sum;
}