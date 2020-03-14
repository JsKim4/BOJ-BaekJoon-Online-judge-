#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 1953 팀배분
int mem[100]; 
int n;
bool hate[100][100];
int main() {
	cin >> n;
	queue<int>teamA;
	queue<int>teamB;
	for (int i = 0; i < n; i++) {
		int m,a;
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> a;
			hate[i][a - 1] = true;
			hate[a - 1][i] = true;
		}
	}
	for (int x = 0; x < n; x++) {
		if (mem[x] == 0) {
			teamA.push(x);
			while (!teamA.empty() || !teamB.empty()) {
				while (!teamA.empty()) {
					int i = teamA.front(); teamA.pop();
					mem[i] = 2;
					for (int j = 0; j < n; j++) {
						if (mem[j] == 0 && hate[i][j] == true) {
							teamB.push(j);
						}
					}
				}
				while (!teamB.empty()) {
					int i = teamB.front(); teamB.pop();
					mem[i] = 1;
					for (int j = 0; j < n; j++) {
						if (mem[j] == 0 && hate[i][j] == true) {
							teamA.push(j);
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		//System.out.println(mem[i]);
		if (mem[i] == 1) {
			teamA.push(i + 1);
		}
		else {
			teamB.push(i + 1);
		}
	}
	cout << teamA.size()<<endl;
	while (!teamA.empty()) {
		cout << teamA.front()<<" "; teamA.pop();
	}
	cout << endl;
	cout << teamB.size() << endl;
	while (!teamB.empty()) {
		cout << teamB.front() << " "; teamB.pop();
	}
}