#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 6086 최대유량
int arr[52][52];
int now[52][52];
int n;
vector<int>way[52];
int main(){
	cin >> n;
	while (n--) {
		char a, b;int  c;
		cin >> a >> b >> c;
		if (a >= 'A' && a <= 'Z')
			a -= 'A';
		else
			a -= 'a' - 26;

		if (b >= 'A' && b <= 'Z')
			b -= 'A';
		else
			b -= 'a' - 26;

		arr[a][b] += c;
		arr[b][a] += c;
		
		way[a].push_back(b);
		way[b].push_back(a);
	}
	int answer = 0;
	while (true) {
		int visited[52];
		for (int i = 0; i < 52; i++)
			visited[i] = -1;

		queue<int>q;
		q.push(0);
		while (!q.empty()) {
			int num = q.front(); q.pop();
			for (int j = 0; j < way[num].size(); j++) {
				int loc = way[num][j];
				if (visited[loc] == -1) {
					if (arr[num][loc] > now[num][loc]) {
						q.push(loc);
						visited[loc] = num;
						if (loc == 25)
							break;
					}
				}
			}
		}

		if (visited[25] == -1)
			break;
		int min_num = 2100000000;
		for (int i = 25; i != 0;i=visited[i]) {
			min_num = min(min_num,arr[visited[i]][i]-now[visited[i]][i]);
		}
		for (int i = 25; i != 0; i = visited[i]) {
			now[visited[i]][i] += min_num;
		}
		answer += min_num;
	}
	cout << answer;
}