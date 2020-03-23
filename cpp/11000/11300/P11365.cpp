#include<iostream>
#include<string>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 11365 !밀비 급일
int main(){
	string str;
	while (true) {
		getline(cin, str);
		if (str == "END")
			break;
		else
			reverse(str.begin(), str.end());
		cout << str << endl;
	}
}