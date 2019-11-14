#include<iostream>
#include<cmath>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
double aToB[1000001][2];
double cToD[1000001][2];
double length[1000001];
// 11662 
int main() {
	double input[8];
	double step[4];

	for (int i = 0; i < 8;i++) {
		scanf("%lf",&input[i]);
	}
	step[0] = (input[2] - input[0]) / 1000000;
	step[1] = (input[3] - input[1]) / 1000000;
	step[2] = (input[6] - input[4]) / 1000000;
	step[3] = (input[7] - input[5]) / 1000000;
	double min = sqrt(((input[4] - input[0]) * (input[4] - input[0])) + ((input[5] - input[1]) * (input[5] - input[1])));
	//printf("%lf \n%lf \n%lf \n%lf\n", step[0], step[2], step[1], step[3]);
	for (int i = 0; i <= 1000000;i++) {
		aToB[i][0] = input[0] + step[0] * i;
		aToB[i][1] = input[1] + step[1] * i;
		cToD[i][0] = input[4] + step[2] * i;
		cToD[i][1] = input[5] + step[3] * i;
		double num = sqrt(((cToD[i][0] - aToB[i][0]) * (cToD[i][0] - aToB[i][0])) + ((cToD[i][1] - aToB[i][1]) * (cToD[i][1] - aToB[i][1])));
		if (min > num)
			min = num;
		//printf("%9lf %9lf %9lf %9lf %9lf\n", aToB[i][0], aToB[i][1], cToD[i][0], cToD[i][1],num);
	}
	printf("%.10lf",min);

}