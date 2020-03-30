#include<iostream>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 2587 대표값2
int arr[5],i=5,s=0;
int main(){
	while (--i>-1) {
		cin >> arr[i];
		s += arr[i];
	}
	sort(arr+0, arr+5);
	cout << s/5 << "\n" << arr[2];
}