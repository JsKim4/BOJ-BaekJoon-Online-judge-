#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 1138 한 줄로 서기
int arr[10];

int n;
void print() {
	for (int i = 0; i < n;i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}
int main() {
	queue<int>q;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	while (q.size() < n) {
		//print();
		for (int i = 0; i < n;i++) {
			if (arr[i] == 0) {
				q.push(i);
				for (int j = i; j >= 0;j--) {
					arr[j]--;
				}
				break;
			}
		}
	}
	while (!q.empty()) {
		cout << q.front()+1 << " ";
		q.pop();
	}
}