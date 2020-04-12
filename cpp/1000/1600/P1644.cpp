#include<iostream>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
// 1644 소수의 연속합
bool s[4000001] = {1,1};
vector<long long>num;
int main(){
	for (int i = 2; i < 150000; i++){
		if (!s[i]){
			for (int j = i * 2; j <= 4000000; j += i)
				s[j] = true;
		}
	}
	int j = 1;
	num.push_back(0);
	for (int i = 1; i <= 4000000;i++) {
		if (!s[i]) {
			num.push_back(i);
			num[j] += num[j - 1]; j++;
		}
	}
	int n;
	cin >> n;
	int l = 0, r = 1;
	int answer = 0;
	while (l < r) {
		int tnum = num[r] - num[l];
		if (tnum > n) {
			l++;
		}
		else if (tnum < n) {
			r++;
		}
		else if (tnum == n) {
			answer++;
			r++;
		}
	}
	cout << answer;
}