#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1312 소수
int main(){
	int a, b,n;
	int mo, na;
	cin >> a >> b >> n;
	mo = a;
	na = a;
	while (n>0){
		mo = na / b;
		na = na % b;
		
		//cout << na <<" "<<mo<< endl;
		if (na < b) {
			n--;
			na *= 10;
		}
	}
	cout << na / b;
}