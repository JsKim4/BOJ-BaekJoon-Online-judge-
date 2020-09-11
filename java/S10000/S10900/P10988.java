package S10000.S10900;

import java.util.Scanner;


// 10988 팰린드롬인지 확인하기
public class P10988 {
    public void solve() {
        Scanner sc = new Scanner(System.in);
        String s;
        s = sc.nextLine();
        for (int i = 0; i < s.length() / 2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
                System.out.println(0);
                return;
            }
        }
        System.out.println(1);
    }

    public static void main(String args[]) {
        new P10988().solve();
    }
}
