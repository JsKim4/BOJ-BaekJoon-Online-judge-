package S11000.S11000;

import java.util.Scanner;

// 11050 이항 계수 1
public class P11050 {
    public void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        int np = 1, kp = 1, nkp = 1;
        for (int i = 1; i <= n; i++) np *= i;
        for (int i = 1; i <= k; i++) kp *= i;
        for (int i = 1; i <= n - k; i++) nkp *= i;
        System.out.println(np / (kp * nkp));
    }

    public static void main(String args[]) {
        new P11050().solve();
    }
}
