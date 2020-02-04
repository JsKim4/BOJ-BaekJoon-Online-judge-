#include <iostream>
#include <queue>
using namespace std;
// 최대 힙
int main() {
	int n;
	priority_queue<int> q;
	scanf("%d", &n);
	while (n--) {
		int m;
		scanf("%d", &m);
		if (m == 0) {

			if (!q.empty()) {
				printf("%d\n", q.top());
				q.pop();	
			}
			else 
				printf("0\n");
		}
		else {
			q.push(m);
		}
	}
	return 0;
}