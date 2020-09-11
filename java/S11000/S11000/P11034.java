package S11000.S11000;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

// 11034 캥거루 세마리2
public class P11034 {
    public static void main(String[] args) throws IOException {
        new P11034().solve();
    }

    private void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = "";


        while ((input = br.readLine()) != null) {
            String[] s1 = input.split(" ");
            int a = Integer.parseInt(s1[0]);
            int b = Integer.parseInt(s1[1]);
            int c = Integer.parseInt(s1[2]);
            System.out.println(((c - b) > (b - a)) ? c - b - 1 : b - a - 1);
        }
    }
}
