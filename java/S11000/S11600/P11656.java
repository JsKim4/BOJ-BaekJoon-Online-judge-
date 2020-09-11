package S11000.S11600;

import java.util.Arrays;
import java.util.Scanner;

//11656 접미사 배열
public class P11656 {
    public static void main(String[] args) {
        String a;
        String s[];
        Scanner sc = new Scanner(System.in);
        a = sc.next();
        s = new String[a.length()];
        for (int i = 0; i < a.length(); i++) {
            s[i] = a.substring(i, a.length());
        }

        Arrays.sort(s);
        for (int i = 0; i < a.length(); i++) {
            System.out.println(s[i]);
        }
    }
}