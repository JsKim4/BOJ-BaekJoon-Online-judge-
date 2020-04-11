#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 11004 k번째 수
int main(){
	priority_queue<int,vector<int>,greater<int>>q;
	int n, k;
	cin >> n >> k;
	while (n--) {
		int a;
		scanf("%d",&a);
		q.push(a);
	}
	while (--k) {
		q.pop();
	}
	cout << q.top();
}