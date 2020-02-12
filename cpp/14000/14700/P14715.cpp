#include<iostream>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
// 14715 전생했더니 슬라임 연구자였던 건에 대하여 (Easy)
int main(){
	bool num[1000001];
	vector<int> s;
	int n;
	int ans = 1;
	num[0] = 1;
	num[1] = 1;
	for (int i = 2; i < 1001; i++) {
		if (!num[i]) {
			s.push_back(i);		
			for (int j = i * 2; j <= 1000000; j += i)
				num[j] = true;
		}
	}
	cin >> n;
	int m = 0;
	while (m<s.size()&&num[n] != 0) {
		if (n%s[m]==0) {
			//printf("%d ",s[m]);
			n /= s[m];
			ans++;
		}
		else
			m++;
	}
	int answer = 0;
	for (; ans / 2 > 0; answer++, ans = ans/2+ans%2);
	printf("%d",answer);


}
