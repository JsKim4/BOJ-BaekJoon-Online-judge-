#include<iostream>
#include<deque>
#pragma warning (disable:4996)
using namespace std;
// 14891 톱니바퀴
deque<int>dq[4];
void turn(int n,int w) {
	int k = 7;
	if (w == 1) {
		while (k--) {
			dq[n].push_back(dq[n].front());
			dq[n].pop_front();
		}
	}
	else {
		while (k--) {
			dq[n].push_front(dq[n].back());
			dq[n].pop_back();
		}
	}
}
int main(){
	char arr[20];
	for (int i = 0; i < 4;i++) {
		scanf("%s",&arr);
		for (int j = 0; j < 8;j++) {
			dq[i].push_back(arr[j]-'0');
		}
	}
	int k;
	scanf("%d",&k);
	while (k--) {
		int n, w;
		int left = 0, right = 0;
		int l_g, r_g;
		scanf("%d %d", &n, &w);

		switch (n) {
		case 1:
			left = 0;
			right = 2;
			break;
		case 2:
			left = 1;
			right = 3;
			break;
		case 3:
			left = 2;
			right = 4;
			break;
		case 4:
			left = 3;
			right = 0;
			break;
		}
		l_g = dq[n - 1][6];
		r_g = dq[n - 1][2];
		turn(n-1,w);
		while (left||right) {
			w *= -1;
			if (left) {
				if (l_g != dq[left - 1][2]) {
					l_g = dq[left - 1][6];
					turn(left - 1,w);
					left -= 1;
				}
				else {
					left = 0;
				}
			}

			if (right) {
				if (r_g != dq[right - 1][6]) {
					r_g = dq[right - 1][2];
					turn(right - 1, w);
					right = (right + 1) % 5;
				}
				else {
					right = 0;
				}
			}
		}
	}
	cout << dq[0][0] + dq[1][0] * 2 + dq[2][0] * 4 + dq[3][0] * 8;

}