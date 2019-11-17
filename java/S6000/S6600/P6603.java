package S6000.S6600;

import java.util.Scanner;
// 6603 로또
public class P6603 {
	static final int maxC = 6;
	int arr[] = new int[13];
	int answer[] = new int[maxC];

	public void sol(int n, int now,int sn) {
		if (now == maxC) {
			print();
			return;
		}
		for (int i = sn; i < now + n + 1 - maxC; i++) {
			answer[now] = i;
			sol(n,now+1,i+1);
		}

	}

	public void print() {
		for (int i = 0; i < maxC; i++) {
			System.out.print(arr[answer[i]]+" ");
		}
		System.out.println();
	}

	public void solve() {
		Scanner sc = new Scanner(System.in);
		while (true) {
			int n = sc.nextInt();
			if (n == 0)
				break;
			for (int i = 0; i < n; i++) {
				arr[i] = sc.nextInt();
			}
			sol(n,0, 0);
			System.out.println();
		}

	}

	public static void main(String[] args) {
		new P6603().solve();
	}
}
