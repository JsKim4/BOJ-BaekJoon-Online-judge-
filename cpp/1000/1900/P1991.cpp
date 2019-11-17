#include<iostream>
#include<vector>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
int list[26][2];
bool check[26];
// 1991 
int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n;i++) {
		char a, b, c;
		cin >> a >> b >> c;
		if (b == '.')
			list[a - 'A'][0] = -1;
		else
			list[a - 'A'][0] = b-'A';

		if (c == '.')
			list[a - 'A'][1] = -1;
		else
			list[a - 'A'][1] = c - 'A';
	}
	vector<int> v;
	int i = 0;
	v.push_back(0);
	while (true) {
		int left = list[v[i]][0];
		int right = list[v[i]][1];
		if (left != -1 && check[left] == 0) {
			v.push_back(left); i = v.size() - 1; check[left] = true;
		}
		else if (right != -1 && check[right] == 0) {
			v.push_back(right); i = v.size() - 1; check[right] = true;
		}
		else {
			i--;
		}
		if (v.size() == n)
			break;
	}
	for (int i = 0; i < n;i++) {
		printf("%c",v[i]+'A');
		check[i] = false;
	}
	printf("\n");
	vector<int> b;
	b.push_back(0);
	while (!b.empty()) {
		int left = list[b.back()][0];
		int right = list[b.back()][1];
		//printf("\n%d %d",left,right);
		if (left != -1 && check[left] == 0) {
			b.push_back(left); check[left] = true;
		}
		else {
			printf("%c", b.back() + 'A');
			b.pop_back();
			if (right != -1 && check[right] == 0) {
				b.push_back(right); check[right] = true;
			}

		}

	}
	printf("\n");
	b.push_back(0);
	for (int i = 0; i < n; i++) {
		check[i] = false;
	}
	while (!b.empty()) {
		int left = list[b.back()][0];
		int right = list[b.back()][1];
		//printf("\n%d %d",left,right);
		if (left != -1 && check[left] == 0) {
			b.push_back(left); check[left] = true;
		}
		else if (right != -1 && check[right] == 0) {
			b.push_back(right); check[right] = true;
		}
		else{
			printf("%c", b.back() + 'A');
			b.pop_back();
		}

	}
}