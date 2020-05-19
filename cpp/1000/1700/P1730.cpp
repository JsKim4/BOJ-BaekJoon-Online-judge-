#include<iostream>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 1730 판화 
int arr[100][100];
char prt[4] = { '.','\|','-','+' };
int n;
bool avail(int i,int j) {
	if (i >= 0 && i < n && j >= 0 && j < n)
		return true;
	return false;
}
void cut(int way,int i,int j) {//1은 위아래 2는 좌우
	if (arr[i][j] == 0) {
		arr[i][j] = way;
	}
	else if (arr[i][j]!=way) {
		arr[i][j] = 3;
	}
}


int main(){
	string s;
	cin >> n;
	cin >> s;
	int nx = 0;
	int ny = 0;

	for (int i = 0; i < s.length();i++) {
		if (s[i] == 'D') {
			if (avail(ny+1, nx)) {
				cut(1, ny, nx);
				ny++;
				cut(1, ny, nx);
			}
		}
		else if (s[i] == 'R') {
			if (avail(ny, nx+1)) {
				cut(2, ny, nx);
				nx++;
				cut(2, ny, nx);
			}
		}
		else if (s[i] == 'U') {
			if (avail(ny-1, nx)) {
				cut(1, ny, nx);
				ny--;
				cut(1, ny, nx);
			}
		}
		else {
			if (avail(ny, nx-1)) {
				cut(2, ny, nx);
				nx--;
				cut(2, ny, nx);
			}
		}
	}
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			printf("%c", prt[arr[i][j]]);
		}
		printf("\n");
	}
}