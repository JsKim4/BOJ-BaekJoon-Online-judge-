#include<iostream>
#include<string>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 1251 단어 나누기
int main(){
	string s;
	cin >> s;
	string min_s = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	for (int i = 1; i < s.length() - 1;i++) {
		for (int j = 1; j < s.length() - i; j++) {
			string s1 = s.substr(0,i);
			string s2 = s.substr(i, j);
			string s3 = s.substr(j+i, s.length()-i-j);

			/*cout << s1 << " " << s2 << " " << s3 << endl;*/
			reverse(s1.begin(), s1.end());

			reverse(s2.begin(), s2.end());
			reverse(s3.begin(), s3.end());
			if (min_s > s1 + s2 + s3) {
				min_s = s1 + s2 + s3;
			}
		}
	}
	cout << min_s;
}