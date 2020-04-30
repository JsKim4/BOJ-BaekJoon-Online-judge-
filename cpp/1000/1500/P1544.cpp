#include<iostream>
#include<string>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
// 1544 사이클 단어
int n;
vector<string> ns;
int main() {
	cin >> n;
	int m = 0;
	while (n--) {
		string s;
		cin >> s;
		if (ns.size() == 0) {
			ns.push_back(s);
		}
		else {
			bool tf = false;
			for (int i = 0; i < s.length();i++) {
				for (int j = 0; j < ns.size();j++) {
					if (ns[j] == s) {
						tf = true;
						break;
					}
				}
				if (tf) {
					break;
				}
				s.push_back(s.front());
				s.erase(0,1);
			}
			if (!tf) {
				ns.push_back(s);
			}
		}
	}
	cout << ns.size();
}