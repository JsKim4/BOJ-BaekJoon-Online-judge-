#include<iostream>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 11931 수 정렬하기

int arr[2000010];
int main(){
	int n;
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + n,greater<int>());
	for (int i = 0; i < n; i++) 
		cout<< arr[i]<<"\n";
}

