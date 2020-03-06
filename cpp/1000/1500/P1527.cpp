#include<iostream>
#include<cmath>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
// 1527 금민수의 개수
vector<int> s;
int n, m;
void gms(int i,int j,int t) {
	if (t == 9)
		return;
	int cnt = j;
	for (int ii = i; ii < j; ii++,cnt++)
		s.push_back((int)pow(10, t) * 4 + s[ii]);
	for (int ii = i; ii < j; ii++, cnt++)
		s.push_back((int)pow(10, t) * 7 + s[ii]);
	gms(j, cnt,t+1);
}
int main() {
	s.push_back(4); s.push_back(7);
	gms(0, 2, 1);
	int n, m;
	cin >> n >> m;
	int i,j;
	for (i = 0; i<s.size() && s[i] < n; i++);
	for (j = s.size() - 1; j >= 0 && s[j] > m; j--);
	cout << j-i+1;
}