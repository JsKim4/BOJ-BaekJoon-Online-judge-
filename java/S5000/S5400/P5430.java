package S5000.S5400;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
// 5430 AC
public class P5430 {
	public void solve() throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(in.readLine());
		while(T--!=0) {
			String order = in.readLine();
			int n = Integer.parseInt(in.readLine());
			String num = in.readLine();
			num = num.substring(1, num.length()-1);
			String[] array = num.split(",");
			int i=0,j=array.length;
			if(n==0)
				j=0;
			boolean r=false;
			for(int w=0;w<order.length();w++) {
				if(order.charAt(w)=='R') {
					r=!r;
				}else {
					if(r) {
						j--;
					}else {
						i++;
					}
					if(j<i) {
						System.out.print("error\n");
						break;
					}
				}
			}
			if(j<i) {
				continue;
			}
			if(j==i) {
				System.out.print("[]\n");
				continue;
			}
			if(!r){
				System.out.print("["+array[i]);
				for(int ni = i+1;ni<=j-1;ni++) {
					System.out.print(","+array[ni]);
				}
				System.out.print("]\n");
			}else {
				System.out.print("["+array[j-1]);
				for(int ni = j-2;ni>=i;ni--) {
					System.out.print(","+array[ni]);
				}
				System.out.print("]\n");
			}
			
		}
		
	}
	public static void main(String[] args) {
		try {
			new P5430().solve();
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
