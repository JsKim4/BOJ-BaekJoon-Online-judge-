#include<iostream>
using namespace std;
#pragma warning (disable:4996)
// 1059 ¼ö2
bool n[1001];
int main() {
	int l,t,num,s=0;
	int le = 0, ri = 0;
	scanf("%d",&l);
	while (l--) {
		scanf("%d",&t);
		n[t] = true;
	}
	scanf("%d",&num);
	for (int i = num + 1; i < 1001; i++) {
		if (n[i])
			break;
		ri++;
	}
	for (int i = num - 1; i > 0; i--) {
		if (n[i])
			break;
		le++;
	}
	printf("%d",n[num]?0:le+ri+le*ri);
}