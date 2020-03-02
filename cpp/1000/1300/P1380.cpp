#include<iostream>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;
// 1380 귀걸이
char girl[100][61];
int gn[100];
int main(){
	int sina = 1;
	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			return 0;
		cin.ignore();
		for (int i = 0; i < n; i++) {
			cin.getline(girl[i], 100,'\n');
		}
		char a; int g;
		for (int i = 0; i < 2 * n - 1;i++) {
			cin >> g >> a;
			gn[g-1]++;
		}
		cout << sina++<<" ";
		for (int i = 0; i < n;i++) {
			if (gn[i] == 1)
				cout << girl[i] << endl;
			gn[i] = 0;
		}

	}
}