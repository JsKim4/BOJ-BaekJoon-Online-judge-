package S1000.S1900;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

// 1920 수 찾기
public class P1920 {

    public void solve() {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        Map<Integer, Boolean> m = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            m.put(a, true);
        }
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            if (m.get(a) != null)
                System.out.println(1);
            else
                System.out.println(0);
        }

    }

    public static void main(String[] args) {
        new P1920().solve();
    }
}
