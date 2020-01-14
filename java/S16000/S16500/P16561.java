package S16000.S16500;

import java.util.Scanner;

public class P16561 {
	int count=0;
	int num;
	public void three(int i,int now) {
		if(i==3){
			if(now==num) {
				count++;
			}
			//System.out.println("");
			return;
		}
		for(int j=3;now+j<=num;j+=3) {
			//System.out.print(j);
			three(i+1,now+j);
		}
		//System.out.println("");
	}
	public void solve() {
		Scanner sc = new Scanner(System.in);
		num = sc.nextInt();
		three(0,0);
		System.out.println(count);
	}
	public static void main(String args[]) {
		new P16561().solve();
	}
}
