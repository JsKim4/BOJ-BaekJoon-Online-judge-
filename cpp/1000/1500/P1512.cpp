#include<iostream>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 1512 주기문으로 바꾸기
int m;
int l[3000][4];
string s;
int init(int j) {
	//cout << j << endl;
	int answer = 0;
	for (int i = 0; i < j;i++) {
		//cout << l[i][0] << " " << l[i][1] << " " << l[i][2] << " " << l[i][3] << endl;
		int sum = 0, Max = 0;
		for (int k = 0; k < 4;k++) {
			if (Max < l[i][k]) {
				Max = l[i][k];
			}
			sum += l[i][k];
			l[i][k] = 0;
		}
		sum -= Max;
		answer += sum;
	}
	return answer;
}
int main(){
	cin >> m;
	cin >> s;
	int answer = 2100000000;
	for (int i = 1; i <= m;i++) {
		for (int j = 0; j < i;j++) {
			for (int k = j; k < s.length(); k += i) {
				if (s[k] == 'A')
					l[j][0]++;
				if (s[k] == 'C')
					l[j][1]++;
				if (s[k] == 'G')
					l[j][2]++;
				if (s[k] == 'T')
					l[j][3]++;
			}
		}
		int tmp = init(i);
		if (answer > tmp)
			answer = tmp;
	}
	cout << answer;
}