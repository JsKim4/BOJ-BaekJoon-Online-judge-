#include<iostream>
#include<queue>
#include<tuple>
#pragma warning (disable:4996)
using namespace std;
//2535 아시아 정보올림피아드
int arr[3];
int main(){
	priority_queue<tuple<int, int, int>,vector<tuple<int, int, int>>,less<tuple<int, int, int>>>q;
	int n;
	cin >> n;
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		q.push(make_tuple(c, a, b));
	}
	for (int i = 0; i < 3;i++) {
		int a, b, c;
		tie(a, b, c) = q.top(); q.pop();
		arr[i] = b;
		if (arr[0] == arr[1]&& arr[0] == arr[2]) {
			i--;
			continue;
		}
		cout << b << " " << c << endl;
	}
}