#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 7567 그릇
int main(){
	char a[51];
	int answer=2,i=0;
	cin >> a;
	while (a[++i] != 0) {
		answer+=2;
		if (a[i] == a[i - 1])
			answer--;
	}
	cout << answer*5;

}