#include<iostream>
#include<vector>
#include<queue>
// 2824 최대공약수
#define INF 1000000000
using namespace std;
bool num[32500];
int arrN[1000];
int arrM[1000];
int main(){	
	vector<int>v;
	priority_queue<int,vector<int>,greater<int>>qN,qM;
	queue<int>answerQ;
	int n,m;
	num[0] = 1;
	num[1] = 1;
	for (int i = 2; i <= 180; i++){
		if (!num[i]){
			for (int j = i*2; j <= 32400; j += i){
				num[j] = true;
			}
		}
	}
	for (int i = 2; i <= 32400; i++) {
		if (!num[i])
			v.push_back(i);
	}
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arrN[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> arrM[i];
	for (int i = 0; i < n; i++) {
		bool tf = false;
		for (int j = 0; j < v.size(); j++) {
			if (arrN[i] == v[j])
				break;
			else if (arrN[i] % v[j] == 0) {
				qN.push(v[j]);
				arrN[i] /= v[j];
				tf = true;
				break;
			}
		}
		if (tf)
			i--;
		else
			qN.push(arrN[i]);
	}

	for (int i = 0; i < m; i++) {
		bool tf = false;
		for (int j = 0; j < v.size(); j++) {
			if (arrM[i] == v[j])
				break;
			else if (arrM[i] % v[j] == 0) {
				qM.push(v[j]);
				arrM[i] /= v[j];
				tf = true;
				break;
			}
		}
		if (tf)
			i--;
		else
			qM.push(arrM[i]);
	}
	while (!qN.empty() && !qM.empty()) {
		if (qN.top() > qM.top()) {
			qM.pop();
		}
		else if (qN.top() < qM.top()) {
			qN.pop();
		}
		else {
			answerQ.push(qN.top());
			qN.pop();
			qM.pop();
		}
	}
	unsigned long long answer=1;
	bool tfinf = false;
	while (!answerQ.empty()) {
		answer *= answerQ.front();
		//cout << answerQ.front() << endl;
		if (answer > INF - 1) 
			tfinf = true;
		answer %= INF;
		answerQ.pop();
	}
	if (tfinf == true) {
		for (int i = INF /10; i>9&&answer < i;i/=10) {
			cout << 0;
		}
	}
	cout << answer;
}