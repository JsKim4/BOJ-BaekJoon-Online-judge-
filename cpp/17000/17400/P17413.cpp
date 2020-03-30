#include<iostream>
#include<string>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 17413 단어 뒤집기 2
int main() {
	string s;
	getline(cin, s);
	string ts;
	int gwal = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '<') {
			if (gwal == 0) {
				reverse(ts.begin(), ts.end());
				cout << ts;
				ts = "";
			}
			ts += "<";
			gwal++;
		}
		else if (s[i] == '>') {
			gwal--;
			ts += ">";
			if (gwal == 0) {
				cout << ts;
				ts = "";
			}
		}
		else if (s[i] == ' '&&gwal==0) {
			reverse(ts.begin(), ts.end());
			cout << ts << ' ';
			ts = "";
		}
		else
			ts += s[i];
	}

	reverse(ts.begin(), ts.end());
	cout << ts << endl;
	
}