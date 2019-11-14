package S1000.S1900;

import java.io.BufferedReader;
import java.io.InputStreamReader;
// 1992 쿼드트리
public class P1992 {
	String line[];
	public void solve() throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		line = new String[n];
		for(int i=0;i<n;i++) {
			line[i] = in.readLine();
		}
		System.out.println(merge(0,0,n));
		
	}
	public String merge(int y,int x,int len) {
		if(len==1)
			return String.valueOf(line[y].charAt(x));
		
		String p1t1=merge(y,x,len/2);
		String p1t2=merge(y,x+len/2,len/2);
		String p2t1=merge(y+len/2,x,len/2);
		String p2t2=merge(y+len/2,x+len/2,len/2);
		if(p1t1.equals(p1t2)&&p1t1.equals(p2t1)&&p1t1.equals(p2t2)&&p1t1.length()==1) {
			return p1t1;
		}
		else {
			return "("+p1t1+p1t2+p2t1+p2t2+")";
		}
		
	}
	public static void main(String[] args) {
		try {
			new P1992().solve();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
