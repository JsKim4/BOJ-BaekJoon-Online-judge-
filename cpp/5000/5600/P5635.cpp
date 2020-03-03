#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
// 5635 생일
int main() {
	priority_queue<tuple<int, int, int, string>, vector<tuple<int, int, int, string>>, less<tuple<int, int, int, string>>> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		string name; int a, b, c;
		cin >> name >> a >> b >> c;
		pq.push(make_tuple(c, b, a, name));
	}
	string name; int a, b, c;
	tie(a, b, c, name) = pq.top();
	cout << name << endl;
	for (int i = 0; i < n - 1;i++) {
		pq.pop();
	}
	tie(a, b, c, name) = pq.top();
	cout << name << endl;

}