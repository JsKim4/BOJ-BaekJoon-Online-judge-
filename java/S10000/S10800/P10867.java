package S10000.S10800;

import java.util.Scanner;

public class P10867 {
	boolean b[] = new boolean[2010];
	public void solve() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i=0;i<n;i++) {
			int a = sc.nextInt();
			b[a+1000] = true;
		}
		for(int i=0;i<=2000;i++) {
			if(b[i]) {
				System.out.print((i-1000)+" ");
			}
		}
	}
	public static void main(String[] args) {
		new P10867().solve();
	}

}
