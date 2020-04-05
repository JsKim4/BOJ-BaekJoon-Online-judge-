#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 1015 수열정리
int arr[50];
int main(){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>p;
	int n,a;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> a;
		p.push({ a,i });
	}
	int i = 0;
	while (!p.empty()) {
		arr[p.top().second] = i++;
		p.pop();
	}
	for (int i = 0; i < n;i++) {
		cout << arr[i]<<" ";
	}

}