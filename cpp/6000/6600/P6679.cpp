#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 6679 싱기한 네자리 숫자
int r10(int n) {
	return n / 1000 + (n % 1000) / 100 + (n % 100) / 10 + (n % 10);
}
int r12(int n) {
	return n / 1728 + (n % 1728) / 144 + (n % 144) / 12 + (n % 12);
}
int r16(int n) {
	return n / 4096 + (n % 4096) / 256 + (n % 256) / 16 + (n % 16);
}
int main(){
	for (int i = 1000; i < 10000;i++) {
		int r1 = r10(i);
		if (r1 == r12(i) && r1 == r16(i)) {
			cout << i << endl;
		}
	}
}