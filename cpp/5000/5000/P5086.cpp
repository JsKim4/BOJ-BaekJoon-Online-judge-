#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 5086 배수와 약수
int main(){
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0)
			return 0;
		if (b % a == 0)
			printf("factor\n");
		else if (a % b == 0) 
			printf("multiple\n");
		else
			printf("neither\n");
	}

}