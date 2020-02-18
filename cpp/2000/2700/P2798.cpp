#include<iostream>
#include<algorithm>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;
// 2798 블랙잭
int main(){
	int n, m;
	int num[100];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	int ab = -1;
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			for (int q = j+1; q < n; q++) {
				if (m - (num[i] + num[j] + num[q]) >= 0) {
					if(ab<0)
						ab = num[i] + num[j] + num[q];
					if(m - ab > m- (num[i] + num[j] + num[q]))
						ab = num[i] + num[j] + num[q];
				}
			}
	printf("%d",ab);
}