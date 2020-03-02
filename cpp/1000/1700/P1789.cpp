#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1789 수들의 합
int main(){
	long long s;
	cin >>s;
	long long answer = 1;
	for (long long i = 2; i < s;i++) {
		s -= i;
		answer++;
	}
	cout << answer;
}