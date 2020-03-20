#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 17406 배열 돌리기 4
int n, m, k;
int arr[50][50];
int temp[50][50];
int kk[6][3];
int bin[] = { 0b000001 ,0b000010 ,0b000100 ,0b001000 ,0b010000 ,0b100000 };
int bim[] = { 0b111110 ,0b111101 ,0b111011 ,0b110111 ,0b101111 ,0b011111 };
int now = 0;
int ns[6];
int Min = 2100000000;
void print() {
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m; j++) {
			cout << temp[i][j];
		}
		cout << endl;
	}cout << endl; cout << endl;
}
void init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			temp[i][j] = arr[i][j];
}
void turn(int sy,int sx,int ey,int ex) {
	if (sy >= ey) {
		return;
	}
	int tempN = 0;
	int nextN = temp[sy+1][sx];
	for (int i = sx; i <= ex; i++) {
		tempN = temp[sy][i];
		temp[sy][i] = nextN;
		nextN = tempN;
	}
	for (int i = sy+1; i <= ey; i++) {
		tempN = temp[i][ex];
		temp[i][ex] = nextN;
		nextN = tempN;
	}
	for (int i = ex-1; i >= sx; i--) {
		tempN = temp[ey][i];
		temp[ey][i] = nextN;
		nextN = tempN;
	}
	for (int i = ey-1; i > sy; i--) {
		tempN = temp[i][sx];
		temp[i][sx] = nextN;
		nextN = tempN;
	}
	turn(sy+1,sx+1,ey-1,ex-1);
}
void solve(int i,int k) {
	if (i == k) {
		for (int j = 0; j < k;j++) {
			turn(kk[ns[j]][0]- kk[ns[j]][2], kk[ns[j]][1]- kk[ns[j]][2], kk[ns[j]][0]+ kk[ns[j]][2], kk[ns[j]][1]+ kk[ns[j]][2]);
		}
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < m;j++) {
				sum += temp[i][j];
			}
			if (sum < Min)
				Min = sum;
		}
		//print();
		init();
		return;
	}
	for (int j = 0; j < k;j++) {
		if ((now|bin[j])!=now) {
			ns[i] = j;
			now |= bin[j];
			solve(i+1,k);
			now &= bim[j];
		}
	}
}
int main(){
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	for (int i = 0; i < k;i++) {
		cin >> kk[i][0] >> kk[i][1] >> kk[i][2];
		kk[i][0]--; kk[i][1]--;
	}
	init();
	solve(0,k);
	cout << Min;
}