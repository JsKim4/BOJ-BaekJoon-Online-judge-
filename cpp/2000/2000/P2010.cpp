#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2010 플러그
int main(){
	int n;
	cin >> n;
	int answer = -n+1;
	while (n--) {
		int a; cin >> a;
		answer += a;
	}
	cout << answer;

}