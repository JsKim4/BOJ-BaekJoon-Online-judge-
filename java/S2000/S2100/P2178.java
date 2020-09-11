package S2000.S2100;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 2178 미로 탐색
public class P2178 {
    int n, m;
    int list[][];
    int way[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public boolean avail(int i, int j) {
        if (i >= 0 && j >= 0 && j < m && i < n)
            return true;
        return false;
    }

    public void dfs(int i, int j, int num) {
        list[i][j] = num;
        for (int w = 0; w < 4; w++) {
            int wi = i + way[w][0];
            int wj = j + way[w][1];
            if (avail(wi, wj)) {
                if (list[wi][wj] == 1 || (list[wi][wj] > num + 1)) {
                    dfs(wi, wj, num + 1);
                }
            }
        }
    }

    public void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(list[i][j]);
            }
            System.out.println();
        }
    }

    public void solve() throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String nm[] = in.readLine().split(" ");
        n = Integer.parseInt(nm[0]);
        m = Integer.parseInt(nm[1]);
        list = new int[n][m];
        for (int i = 0; i < n; i++) {
            String l[] = in.readLine().split("");
            for (int j = 0; j < m; j++) {
                list[i][j] = Integer.parseInt(l[j]);
            }
        }
        dfs(0, 0, 1);
        //print();
        System.out.println(list[n - 1][m - 1]);
    }

    public static void main(String[] args) throws IOException {
        new P2178().solve();
    }
}
