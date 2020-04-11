#include<iostream>
#include<cmath>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
long long rt(int a,int n) {
	return pow(a, n);
}
int main(){
	int a, b;
	int n;
	cin >> a >> b >> n;
	long long sum = 0;
	while (n--) {
		int t; cin >> t;
		sum += (t * rt(a, n));
	}
	int i = 1;
	while ((sum / rt(b, i))!= 0)i++;
	while (i--) {
		cout << (sum % rt(b, i + 1))/rt(b,i)<<" ";
	}
}