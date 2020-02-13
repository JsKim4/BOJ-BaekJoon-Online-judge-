#include<iostream>
#include<deque>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 17822 원판돌리기
deque<int>pan[50];
queue<pair<int, int>> tempq;
int n, m, t;
int way[][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool cc;
int numn;
int ii;
int jj;
int iii;
int jjj;
bool avail(int i,int j) {
	if (i >= 0 && i < n && j >= 0 && j < m)
		return true;
	return false;
}
void turn(int x, int d, int k) {
	if (d == 1) {
		for (int i = 0; i < k; i++) {
			pan[x].push_back(pan[x].front());
			pan[x].pop_front();
		}
	}
	else {
		for (int i = 0; i < k; i++) {
			pan[x].push_front(pan[x].back());
			pan[x].pop_back();
		}
	}
}
void print() {
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			cout << pan[i][j] << " ";
		}
		cout << "\n";
	}
}
bool remove(int i,int j) {
	numn = pan[i][j];
	cc = false;
	for (int w = 0; w < 4; w++) {
		ii = i + way[w][0];
		jj = j + way[w][1];
		
		if (jj == -1) 
			jj = m - 1;
		else if (jj == m)
			jj = 0;

		if (avail(ii,jj)&&pan[ii][jj]==numn) {
			cc = true;
			break;
		}
	}
	if (!cc)
		return false;
	tempq.push(make_pair(i, j));
	while (!tempq.empty()) {
		int len = tempq.size();
		for (int z = 0; z < len; z++) {
			ii = tempq.front().first;
			jj = tempq.front().second;
			pan[ii][jj] = 0;
			tempq.pop();
			for (int w = 0; w < 4;w++) {
				iii = ii + way[w][0];
				jjj = jj + way[w][1];

				if (jjj == -1) 
					jjj = m - 1;
				else if (jjj == m) 
					jjj = 0;
				
				if (avail(iii, jjj) && pan[iii][jjj] == numn) {
					tempq.push(make_pair(iii,jjj));
				}
			}
		}
	}
	return true;
}
int main(){
	int num;
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d",&num);
			pan[i].push_back(num);
		}
	}
	//cout << "\n";
	int x, d, k;
	bool ck = false;
	double sum = 0;
	int cnt = 0;
	while (t--) {
		cin >> x >> d >> k;
		for (int i = x; i <= n;i+=x) 
			turn(i-1,d,k);
		//print();
		//cout << "\n";
		ck = false;
		sum = 0;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (pan[i][j] > 0) {
					sum += pan[i][j];
					cnt++;
					if(remove(i, j))
						ck=true;
				}
			}
		}
		if (!ck) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (pan[i][j] > 0) {
						if (sum / cnt < pan[i][j]) {
							pan[i][j]--;
						}
						else if (sum / cnt > pan[i][j])
							pan[i][j]++;
					}
				}
			}
		}
		//print();
	}
	int sums = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (pan[i][j] > 0)
				sums += pan[i][j];
		}
	}
	printf("%d",sums);
}