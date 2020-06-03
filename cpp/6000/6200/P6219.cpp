#include<iostream>
using namespace std;
bool num[4000001];
//6219  소수의 자격
int main(){
	num[0] = 1;
	num[1] = 1;
	for (int i = 2; i <= 2000; i++){
		if (!num[i]){
			for (int j = i*2; j <= 4000000; j += i){
				num[j] = true;
			}
		}
	}
	int a, b, c;
	int answer = 0;
	cin >> a >> b >> c;
	for (int i = a; i <= b;i++) {
		if (!num[i]) {
			int j = i;
			while (j > 0) {
				if ((j % 10) == c) {
					answer++;
					break;
				}
				j /= 10;
			}
		}
	}
	cout << answer;
}