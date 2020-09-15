package S14000.S14600;

import java.util.Scanner;

public class P14659 {
    public static void main(String[] args) {
        new P14659().solve();
    }

    private void solve() {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int answer = 0;
        int now = 0;
        int height = -1;

        for (int i = 0; i < n; i++) {
            int num = sc.nextInt();
            if (num > height) {
                height = num;
                now = 0;
            } else {
                now++;
            }

            if(answer < now)
                answer = now;
        }
        System.out.println(answer);

    }
}
