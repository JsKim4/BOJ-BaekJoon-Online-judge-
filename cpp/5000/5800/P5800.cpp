#include<iostream>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 5800 성적 통계
int main() {
	int t;
	cin >> t;
	for (int x = 1; x <= t;x++) {
		int score[100];
		int n; cin >> n;
		for (int i = 0; i < n; i++)
			cin >> score[i];
		sort(score, score + n);
		int gap = 0;
		for (int i = 0; i < n - 1;i++) {
			if (score[i + 1] - score[i] > gap)
				gap =  score[i + 1] - score[i];
		}
		cout << "Class " << x << endl;
		cout << "Max "<<score[n-1]<<", Min "<<score[0]<<", Largest gap "<<gap<<endl;
	}
}