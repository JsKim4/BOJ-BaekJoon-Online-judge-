#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 18258 큐2
queue<int>q;
int main(){
	int n;
	scanf("%d",&n);
	while (n--) {
		char s[10];
		scanf("%s",&s);
		if (s[0] == 'p') {
			if (s[1] == 'u') {
				int a;
				scanf("%d", &a);
				q.push(a);
				continue;
			}
			if (q.empty())
				printf("-1");
			else {
				printf("%d", q.front());
				q.pop();
			}
		}
		else if (s[0] == 'b') {
			if (q.empty())
				printf("-1");
			else
				printf("%d",q.back());
		}
		else if (s[0] == 'f') {
			if (q.empty())
				printf("-1");
			else
				printf("%d", q.front());
		}
		else if (s[0] == 'e') {
			printf("%d", q.empty());
		}
		else if (s[0] == 's') {
			printf("%d", q.size());
		}
		printf("\n");
	}
}