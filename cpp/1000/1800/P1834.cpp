#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1834 나머지와 몫이 같은 수
int main(){
	long long n;
	cin >> n;
	long long sum = 0;
	for (int i = 1; i < n;i++) {
		sum += n * i + i;
	}
	cout << sum;
}