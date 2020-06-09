#include<iostream>
#include<vector>
#include<deque>
#pragma warning (disable:4996)
using namespace std;
#define hund 100000000
// 2407 조합
int main(){
	int n, m;
	vector<int> narray;
	vector<int> marray;
	cin >> n >> m;
	for (int i = n; i > n - m;i--) {
		narray.push_back(i);
	}
	for (int i = 2; i <= m;i++) {
		marray.push_back(i);
	}
	
	
	for (int i = 0; i < marray.size(); i++) {
		for (int j = 0; marray[i] != 1 && j < narray.size();j++) {
			for (int k = 2; marray[i]!=1 && k <= m;k++) {
				if (marray[i] % k == 0 && narray[j] % k == 0) {
					marray[i] /= k;
					narray[j] /= k;
					k--;
				}
			}
		}
	}
	long long result = 1;
	long long first = 0;
	long long second = 0;
	for (int num : narray) {
		result *= num;
		second *= num;
		first *= num;
		second += result / hund;
		result %= hund;
		first += second / hund;
		second %= hund;
	}
	second += result / hund;
	result %= hund;
	first += second / hund;
	second %= hund;
	if (first == 0) {
		if (second==0) {
			cout << result;
		}
		else {
			cout << second<<result;
		}
	}
	else {
		cout << first << second << result;
	}
	
}