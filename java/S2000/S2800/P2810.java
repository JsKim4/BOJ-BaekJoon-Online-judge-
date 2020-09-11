package S2000.S2800;

import java.util.Scanner;

public class P2810 {
    public static void main(String[] args) {
        new P2810().solve();
    }

    private void solve() {
        Scanner sc = new Scanner(System.in);
        sc.nextLine();
        String s = sc.nextLine();
        int nowForm = 0;
        int answer = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'L') {
                if (nowForm == 0) {
                    nowForm = 1;
                    answer++;
                } else if (nowForm == 1) {
                    nowForm = 2;
                    answer++;
                } else {
                    nowForm = 1;
                }
            } else {
                answer++;
            }
        }
        System.out.println(answer);
    }
}
