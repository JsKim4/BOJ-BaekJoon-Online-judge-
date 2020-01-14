package S10000.S10900;

import java.util.Scanner;
// 10984 내 학점을 구해줘
public class P10984 {
	public void solve() {
		Scanner sc = new Scanner(System.in);
		int T;
		T = sc.nextInt();
		while(T--!=0) {
			int n;
			int sug=0;
			double suc=0;
			int g=0;
			double c=0;
			n=sc.nextInt();
			for(int i=0;i<n;i++) {
				g=sc.nextInt();
				c=sc.nextDouble();
				sug+=g;
				suc+=(g*c);
			}
			System.out.println(String.format("%d %.1f",sug,suc/sug));
			
		}
	}

	public static void main(String args[]) {
		new P10984().solve();
	}
}
