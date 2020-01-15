#include<iostream>
#include<stack>
#pragma warning (disable:4996)
using namespace std;
// 2812 크게 만들기
char n[500001]; int N,K,k;
int main() {
	scanf("%d %d",&N,&K);
	k = K;
	scanf("%s",&n);
	stack<char>s;
	int j = 1;
	s.push(n[0]);
	while (K > 0 && j!=N) {
		//printf("%d %d %c %c %d\n",s.size(),j,n[j],s.empty()?'E': s.top(),K);
		if (!s.empty()&&s.top() < n[j]) {
		//	printf("pop\n");
			s.pop(); K--;
		}
		else {
		//	printf("push\n");
			s.push(n[j++]);
		}
	}
	//printf("%d %d", s.size(),j);
	while (s.size() > N - k) {
		//printf("\npop %d %c %d\n", s.size(), s.top(), K);
		s.pop(); K--;
	}
	while (s.size()<N-k) {
		s.push(n[j++]);
	}
	//printf("%d %d",s.size(),N-k);
	n[N - k] = 0;
	for (int i = N - k; i > 0; i--) {
		n[i - 1] = s.top(); s.pop();
	}
	printf("%s",n);
}