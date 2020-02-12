#include <iostream>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
// 2785 체인
int main() {
	int n, s=0, A[500000];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &A[i]);

	sort(A, A + n);

	for (int i = 0; i < n; i++) {
		int answer = n - i - 1;
		s += A[i];
		if (s >= answer) {
			printf("%d", answer);
			return 0;
		}
	}
}