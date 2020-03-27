#include<iostream>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 1259 팰린드롬수
int main(){
	while (true) {
		string a;
		cin >> a;
		if (a == "0")
			break;
		bool b = true;
		while (a.size() > 1) {
			if (a.front() != a.back())
				b = false;
			a.erase(0, 1);
			a.pop_back();
		}
		if (b)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	
}