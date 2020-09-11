package S1000.S1000;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class P1016 {
    public static void main(String[] args) {
        new P1016().solve();
    }

    List<Long> minusNumbers;

    private void solve() {
        Scanner sc = new Scanner(System.in);
        long min = sc.nextLong();
        long max = sc.nextLong();

        List<Long> prime = new ArrayList<>();
        long arr[] = new long[1001];
        arr[0] = 1;
        arr[1] = 1;

        for (int i = 2; i * i <= 1000; i++) {
            if (arr[i] == 0) {
                for (int j = i * 2; j <= 1000; j += i) {
                    arr[j] = 1;
                }
            }
        }
        for (int i = 2; i <= 1000; i++) {
            if (arr[i] == 0) {
                prime.add(i * 1L);
            }
        }
        prime = prime.stream().map(i -> i * i).collect(Collectors.toList());
        boolean resultArr[] = new boolean[1000001];

        for (Long aLong : prime) {
            for (long i = aLong; max - min + i <= 1000000; i += aLong) {
                resultArr[(int) (max - min + i)] = true;
            }
        }

        int result = 0;
        for (int i = 0; i < max - min; i++) {
            if (resultArr[i] == false)
                result++;
        }
        System.out.println(result);
    }

}
