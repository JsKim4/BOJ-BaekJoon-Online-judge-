package S14000.S14600;

import java.util.Scanner;

// 14624 전북대학교
public class P14624 {
    public void solve() {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        if (n % 2 == 0) {
            System.out.println("I LOVE CBNU");
            return;
        }
        for (int i = 0; i < n; i++)
            System.out.print("*");
        System.out.print("\n");
        n = n / 2 + 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                System.out.print(" ");
            }
            System.out.print("*");
            for (int j = 0; j < i * 2 - 1; j++) {
                System.out.print(" ");
            }
            if (i != 0)
                System.out.print("*");
            System.out.print("\n");
        }

    }

    public static void main(String args[]) {
        new P14624().solve();
    }
}
