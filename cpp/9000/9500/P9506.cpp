#include<iostream>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
// 9506 약수들의 합
int main(){
	while (1) {
		int n;
		cin >> n;
		if (n == -1)
			break;
		vector<int>v;
		int sum = 0;
		for (int i = 1; i < n;i++) {
			if (n % i == 0) {
				sum += i;
				v.push_back(i);
			}
		}
		if (sum == n) {
			cout << n<<" = ";
			for (int i = 0; i < v.size() - 1;i++) {
				cout << v[i] <<" + ";
			}
			cout << v[v.size()-1]<<endl;
		}
		else {
			cout << n << " is NOT perfect." << endl;
		}
	}
}