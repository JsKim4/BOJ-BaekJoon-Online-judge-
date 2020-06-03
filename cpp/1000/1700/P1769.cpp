#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1769  3의 배수
char arr[1000001];
int main(){
	scanf("%s",&arr);
	int n = 0;
	int c = 1;
	for (int i = 0; arr[i] != 0;i++) 
		n += arr[i] - '0';
	while (n >= 10) {
		int tn = n;
		n = 0;
		while (tn>0) {
			n += tn % 10;
			tn /= 10;
		}
		c++;
	}
	if (arr[1] == 0)
		c = 0;
	cout << c<<endl;
	cout << (n % 3 == 0 ? "YES" : "NO");
}