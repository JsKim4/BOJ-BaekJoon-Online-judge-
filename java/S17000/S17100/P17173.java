package S17000.S17100;

import java.util.Scanner;

// 17173 배수들의 합
public class P17173 {
	boolean num[] = new boolean[1001];

	public void solve() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt();
		int t,sum=0;
		for (int i = 0; i < m; i++) {
			t = sc.nextInt();
			for (int j = t; j <= n; j += t)
				num[j] = true;
		}
		for (int i = 0; i <= n; i++) {
			if(num[i])
				sum+=i;
		}
		System.out.println(sum);
	}

	public static void main(String args[]) {
		new P17173().solve();
	}
}
