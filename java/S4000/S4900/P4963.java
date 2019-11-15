package S4000.S4900;

import java.util.Scanner;
// 4963 섬의 개수
public class P4963 {
	int p[][];
	int way[][]= {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
	public boolean avail(int y,int x) {
		if(x>=0&&x<p[0].length&&y>=0&&y<p.length)
			return true;
		return false;
	}
	public void dfs(int y,int x) {
		p[y][x]=0;
		for(int i=0;i<8;i++) {
			int wy = y+way[i][0];
			int wx = x+way[i][1];
			if(avail(wy,wx)&&p[wy][wx]!=0) {
				dfs(wy,wx);
			}
		}
	}
	public void solve() {
		Scanner sc = new Scanner(System.in);
		while (true) {
			int w = sc.nextInt();
			int h = sc.nextInt();
			if (w == 0 && h == 0)
				return;
			p = new int[h][w];
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					p[i][j] = sc.nextInt();
				}
			}
			int count = 0;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if(p[i][j]==1) {
						count++;
						dfs(i,j);
					}
				}
			}
			System.out.println(count);
			

		}
	}

	public static void main(String args[]) {
		new P4963().solve();
	}
}
