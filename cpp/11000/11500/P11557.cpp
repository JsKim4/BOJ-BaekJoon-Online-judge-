#include<iostream>
#include<queue>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 11557 Yangjojang of The Year
int main(){
	int T; cin >> T;
	while (T--) {
		priority_queue<pair<int, string>,vector<pair<int, string>>,less<pair<int, string>>> pq;
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			string ts; int tn;
			cin >> ts >> tn;
			pq.push(make_pair(tn, ts));
		}
		cout << pq.top().second << endl;
	}
}