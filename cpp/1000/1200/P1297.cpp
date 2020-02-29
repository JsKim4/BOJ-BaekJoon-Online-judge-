#include<iostream>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;
// 1297 TV크기
int main(){
	int a, b, c;
	cin >> c >> b >> a;
	cout<< (int)(b * sqrt(pow(c, 2) / (pow(a, 2) + pow(b, 2)))) <<" "<< (int)(a * sqrt(pow(c, 2) / (pow(a, 2) + pow(b, 2))));

}