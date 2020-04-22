#include<iostream>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 1543 문서 검색
int main(){
	string source;
	string target;
	int s=0;
	int answer = 0;
	getline(cin, target);
	getline(cin, source);
	for (int i = 0; i < target.length();i++) {
		if (target[i] == source[s]) {
			s++;
			if (s == source.length()) {
				s = 0;
				answer++;
			}
		}
		else {
			i -= s;
			s = 0;
		}
	}
	cout << answer;
}