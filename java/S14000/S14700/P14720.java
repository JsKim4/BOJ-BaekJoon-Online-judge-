package S14000.S14700;

import java.util.Scanner;

// 14720 우유 축제
public class P14720 {
    public static void main(String[] args) {
        new P14720().solve();
    }

    private void solve() {
        Scanner sc = new Scanner(System.in);
        int milk = 0;
        int result = 0;
        int n = sc.nextInt();
        while (n-- > 0) {
            if(milk == sc.nextInt()){
                result++;
                milk=(milk+1)%3;
            }
        }
        System.out.println(result);
    }
}