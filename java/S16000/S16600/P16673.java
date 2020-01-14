package S16000.S16600;

import java.util.Scanner;
// 16673 고려대학교에는 공식 와인이 있다
public class P16673 {
	public void solve() {
		Scanner sc = new Scanner(System.in);
		int c,k,p;int result=0;
		c=sc.nextInt();
		k=sc.nextInt();
		p=sc.nextInt();
		for(int i=1;i<=c;i++) {
			result +=k*i+p*i*i;
			//System.out.println(result);
		}
		System.out.println(result);
		
	}
	public static void main(String args[]) {
		new P16673().solve();
	}
}
