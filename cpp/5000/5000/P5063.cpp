#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 5063 TGN
int main(){
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if ( b-c == a) {
			cout << "does not matter" << endl;
		}
		else if ( b-c > a) {
			cout << "advertise" << endl;
		}
		else {
			cout << "do not advertise" << endl;
		}
	}
}