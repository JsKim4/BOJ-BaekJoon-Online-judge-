#include<iostream>
#include<vector>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 7682 틱택토 
vector<pair<int, int>>v[9] = {
	{{1,2},{3,6},{4,8}},
	{{0,2},{4,7}},
	{{0,1},{5,8},{4,6}},
	{{0,6},{4,5}},
	{{3,5},{1,7},{0,8},{6,2}},
	{{3,4},{2,8}},
	{{0,3},{2,4},{7,8}},
	{{1,4},{6,8}},
	{{0,4},{2,5},{6,7}}
};
int main() {
	while (true) {
		string s;
		cin >> s;
		int arr[] = { 0,0,0,0,0,0,0,0,0 };
		if (s == "end")
			break;
		int x = 0, o = 0;
		bool mt = false, nt = false;
		for (int i = 0; i < 9; i++) {
			if (s[i] == 'X')
				x++;
			if (s[i] == 'O')
				o++;

			if (s[i] != '.') {
				char c = s[i];
				for (int j = 0; j < v[i].size(); j++) {
					if (c == s[v[i][j].first] && c == s[v[i][j].second]) {
						if (c == 'X')
							mt = true;
						else
							nt = true;
					}
				}
			}
		}
		bool tf = (x == o + 1 || x == o);
		if ((nt && x != o) || (mt&&x == o))
			tf = false;
		if (nt&&mt)
			tf = false;


		if (tf && (nt || mt || x + o == 9))
			cout << "valid\n";
		else
			cout << "invalid\n";
	}

}