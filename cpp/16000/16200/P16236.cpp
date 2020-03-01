#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 16236 아기상어
int n;
int sea[20][20];
int way[][2] = { {-1,0},{0,-1},{0,1},{1,0} };
class whale {
public:
	int size=2;
	int eat=0;

	void eating() {
		eat++;
		if (size == eat) {
			size++;
			eat = 0;
		}
	}

};
bool avail(int i,int j) {
	if (i >= 0 && i < n && j >= 0 && j < n)
		return true;
	return false;
}
void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%5d", sea[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}
int main() {
	queue<pair<int, int>>q;
	queue<pair<int, int>>mq;
	int ws = 2;
	cin >> n;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			cin >> sea[i][j];
			if (sea[i][j] == 0)
				sea[i][j] = -1;
			if (sea[i][j] == 9) {
				sea[i][j] = -1;
				q.push({ i,j });
			}
		}
	}
	int answer = 0;
	int time = 1;
	whale baby;
	while (!q.empty()) {
		int len = q.size();
		queue<pair<int, int>>availEat;
		for (int i = 0; i < len;i++) {
			int y = q.front().first, x = q.front().second; q.pop();
			for (int w = 0; w < 4;w++) {
				int wy = y + way[w][0], wx = x + way[w][1];
				
				if (avail(wy, wx)) {
					if (sea[wy][wx] == -1) {
						q.push({ wy,wx });
						mq.push({ wy,wx });
						sea[wy][wx] = -2;
					}
					else if (sea[wy][wx] < baby.size&& sea[wy][wx]>0) {
						availEat.push({ wy,wx });
					}
					else if(sea[wy][wx] == baby.size){
						sea[wy][wx] *= -1000;
						q.push({ wy,wx });
						mq.push({ wy,wx });
					}
				}
			}
		}
		if(!availEat.empty()){
			answer += time; baby.eating();
			len = 0; 
			while (!q.empty())
				q.pop();
			while (!mq.empty()) {
				int ty = mq.front().first, tx = mq.front().second; mq.pop();
				if (sea[ty][tx] < -1000)
					sea[ty][tx] /= -1000;
				else
					sea[ty][tx] = -1;
			}
			int y = availEat.front().first, x = availEat.front().second; availEat.pop();
			while (!availEat.empty()) {
				int ty = availEat.front().first, tx = availEat.front().second; availEat.pop();
				if (ty < y) {
					y = ty; x = tx;
				}
				else if (ty == y && tx < x) {
					y = ty; x = tx;
				}
			}
			sea[y][x] = -1;
			q.push({ y,x });
			time = 0;
		}
		//cout << answer <<" "<<baby.size<< endl;
		//print();
		time++;
	}
	cout << answer;

}