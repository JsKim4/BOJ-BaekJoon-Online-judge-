#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 11723 집합
char order[][10] = { "add","remove","check","toggle","all","empty" };
int o[22] = {0b0,0b1};
int main() {
	int M; scanf("%d",&M);
	char ord[10];
	int home = 0;
	for (int i = 2; i <= 20;i++) {
		o[i] = o[i - 1] * 2;
	}
	o[21] = 0b11111111111111111111;
	while (M--)
	{
		scanf("%s",&ord);
		int i, n;
		if (ord[0] == 'a')
			if (ord[1] == 'd')
				i = 0;
			else
				i = 4;
		else if (ord[0] == 'r')
			i = 1;
		else if (ord[0] == 'c')
			i = 2;
		else if (ord[0] == 't')
			i = 3;
		else if (ord[0] == 'e')
			i = 5;
		switch (i){
		case 0:
			scanf("%d",&n);
			home |= o[n];
			break;
		case 1:
			scanf("%d", &n);
			home &= (o[n]^o[21]);
			break;
		case 2:
			scanf("%d", &n);
			printf("%d\n", !!(home & o[n]));
			break;
		case 3:
			scanf("%d", &n);
			if (home & o[n])
				home &= (o[n] ^ o[21]);
			else
				home |= o[n];
			break;
		case 4:
			home |= o[21];
			break;
		case 5:
			home &= o[0];
			break;
		}
	}
}