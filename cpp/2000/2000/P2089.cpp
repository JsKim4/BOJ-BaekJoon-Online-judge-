#include<iostream>
using namespace std;
bool a[100000];
int main() {
	int answer;
	scanf("%d", &answer);
	int i;
	for (i = 0;; i++) {
		if (answer == 1 || answer == 0)
			break;
		a[i] = answer % 2 == 0 ? 0 : 1;
		//printf("%d %d\n",answer,a[i]);
		if (answer < 0)
			answer = answer / -2 + (answer % 2 == 0 ? 0 : 1);
		else
			answer = answer /= -2;
	}
	printf("%d", answer);
	for (int j = i - 1; j >= 0; j--) {
		if (a[j])
			printf("1");
		else
			printf("0");
	}
}