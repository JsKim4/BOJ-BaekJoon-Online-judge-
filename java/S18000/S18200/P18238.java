package S18000.S18200;

import java.util.Scanner;

public class P18238 {
    public static void main(String[] args) {
        new P18238().solve();
    }

    private void solve() {
        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();

        int now = 'A';
        int answer = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int len = Math.abs(now - c);
            answer += len > 26-len ? 26-len : len;
            now = c;
        }
        System.out.println(answer);

    }
}
