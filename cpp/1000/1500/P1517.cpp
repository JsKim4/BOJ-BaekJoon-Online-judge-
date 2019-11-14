#include<iostream>
#pragma warning (disable:4996)
using namespace std;

int arr[500001];
int temp[500001];
long long cnt = 0;
// 1517
void merge(int left,int right) {
	int mid = (left + right) / 2;
	int l = left;
	int r = mid+1;
	int k = left;
	while (l != mid + 1 && r != right + 1) {
		if (arr[l] <= arr[r]) {
			temp[k++] = arr[l++];
		}
		else {
			temp[k++] = arr[r++];
			cnt+=mid-l+1;
			//]printf("cnt ++ %d\n", cnt);
		}
	}
	if (l == mid + 1) {
		l = r;
	}
	for (; k <= right;k++) {
		temp[k] = arr[l++];
	}
	for (int i = left; i <= right; i++) {
		arr[i] = temp[i];
		//printf("%d : %d\n",i, arr[i]);
	}
	//printf("\n");
}



void mergeSort(int left,int right) {
	if (right == left)
		return;

	int mid = (left + right) / 2;
	mergeSort(left,mid);
	mergeSort(mid + 1, right);
	merge(left,right);
}
int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n;i++) {
		scanf("%d",&arr[i]);
	}
	mergeSort(0, n - 1);
	/*for (int i = 0; i < n; i++) {
		printf("%d\n",arr[i]);
	}*/
	printf("%lld\n",cnt);
}