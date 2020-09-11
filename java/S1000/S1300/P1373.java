package S1000.S1300;

import java.util.Scanner;

// 1373 2진수 8진수
public class P1373 {
    public static int mul(int num) {
        int n = 1;
        for (int i = 1; i < num; i++) {
            n *= 2;
        }
        return n;
    }

    public static void main(String[] args) {


        Scanner sc = new Scanner(System.in);
        String s = "";
        String answer = "";
        s = sc.nextLine();
        int count = 0;
        int d = 0;
        int c = s.length() / 3 - (s.length() % 3 == 0 ? 1 : 0);
        int num[] = new int[s.length() / 3 + (s.length() % 3 > 0 ? 1 : 0)];
        //System.out.print(num.length+" "+c);
        for (int i = s.length() - 1; i >= 0; i--) {
            count++;
            if (s.charAt(i) == '1') {
                d += mul(count);
            }
            if (count == 3) {
                count = 0;
                num[c--] = d;
                d = 0;
            }
        }
        if (d != 0) {
            num[0] = d;
        }
        boolean b = true;
        for (int i = 0; i < num.length; i++) {
            if (b && num[i] == 0)
                continue;
            System.out.print(num[i]);
            b = false;
        }
        if (b)
            System.out.print(0);
    }
}