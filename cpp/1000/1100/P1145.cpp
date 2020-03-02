#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1145 적어도 대부분의 배수
int n[5];
int main(){
	int i;
	for (i = 0; i < 5; i++)
		cin >> n[i];
	i = 1;
	while (i++) {
		int cnt = 0;
		for (int j = 0; j < 5; j++)
			if (i % n[j] == 0 && i>=n[j])
					cnt++;
			/*if (i % n[j] == 0)
					if (!(i == n[j]))
						cnt++;*/
		if (cnt > 2)
			break;
	}
	cout << i;
}