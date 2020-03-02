#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 2822 점수 계산
queue<int> score[151];
vector<int>v;
int main(){
	for (int i = 0; i < 8;i++) {
		int n; cin >> n;
		score[n].push(i + 1);
	}
	int cnt = 0,answer=0;
	for (int i = 150; i >= 0 && cnt < 5; i--) {
		if(!score[i].empty()){
			v.push_back(score[i].front());
			score[i].pop(); 
			cnt++; 
			answer += i++;
		}
	}
	sort(v.begin(), v.end());
	cout << answer<<endl;
	for (int i = 0; i < 5;i++) {
		cout << v[i]<<" ";
	}


}