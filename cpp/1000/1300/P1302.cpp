#include<iostream>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 1302 베스트셀러
string sl[1000];
int sln[1000];
int main(){
	int n;
	cin >> n;
	int k = 0;
	while (n--) {
		string s;
		cin >> s;
		bool tf = true;
		for (int j = 0; j < k;j++) {
			if (sl[j] == s) {
				tf = false;
				sln[j]++;
				break;
			}
		}
		if (tf) {
			sl[k] = s;
			sln[k]++;
			k++;
		}
	}
	int j = 0;
	for (int i = 0; i < k;i++) {
		if (sln[i] > sln[j]) {
			j = i;
		}
		else if (sln[i] == sln[j] && sl[i] < sl[j]) {
			j = i;
		}
	}
	cout<<sl[j];
}