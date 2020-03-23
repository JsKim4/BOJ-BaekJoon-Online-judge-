#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2863 5와 6의 차이
int main(){
	char a[8], b[8];
	int ma[8], mb[8];
	cin >> a >> b;
	int an = 0,am=0;
	int bn = 0,bm=0;
	for (int i = 0; a[i] != 0; i++) {
		if (a[i] == '5')
			ma[i] = '6';
		else
			ma[i] = a[i];
		if (a[i] == '6')
			a[i] = '5';
	}
	for (int i = 0; b[i] != 0; i++) {
		if (b[i] == '5')
			mb[i] = '6';
		else
			mb[i] = b[i];
		if (b[i] == '6')
			b[i] = '5';
	}
	for (int i = 0; a[i] != 0; i++) {
		an *= 10;
		an += a[i] - '0';
		am *= 10;
		am += ma[i] - '0';
	}
	for (int i = 0; b[i] != 0; i++) {
		bn *= 10;
		bn += b[i] - '0';
		bm *= 10;
		bm += mb[i] - '0';
	}
	cout << an + bn << " " << bm + am;

}