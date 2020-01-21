#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1076 저항
char color[][11] = {"black","brown","red","orange","yellow","green","blue","violet","grey","white"};
int num[] = {0,1,2,3,4,5,6,7,8,9};
char ze[][11] = {"","0","00","000","0000","00000","000000","0000000","00000000","000000000"};
int main() {
	int result=0;
	char a[11];
	int n[3];
	for (int i = 0; i < 3;i++) {
		scanf("%s",&a);
		switch (a[0]) {
		case 'b':
			switch (a[1]) {
			case 'l':
				n[i] = a[2] == 'a' ? 0 : 6;
				break;
			case 'r':
				n[i] = 1;
				break;
			}
			break;
		case 'r':
			n[i] = 2;
			break;
		case 'o':
			n[i] = 3;
			break;
		case 'y':
			n[i] = 4;
			break;
		case 'g':
			n[i] = a[3] == 'e' ? 5 : 8;
			break;
		case 'v':
			n[i] = 7;
			break;
		case 'w':
			n[i] = 9;
			break;
		}
	}
	result += num[n[0]] * 10;
	result += num[n[1]];
	printf("%d%s", result, result!=0?ze[n[2]]:"");
}