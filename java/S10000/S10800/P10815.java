package S10000.S10800;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

// 10815 숫자카드
public class P10815 {
    int nArray[];

    public boolean search(int num, int r) {
        int left = 0;
        int right = r;
        if (nArray[r] == num)
            return true;
        while (true) {
            int mid = (left + right) / 2;
            if (nArray[mid] == num) {
                return true;
            }

            if (left == mid)
                return false;
            if (nArray[mid] > num) {
                right = mid;
            } else {
                left = mid;
            }
        }
    }

    public void solve() throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        String nA[] = in.readLine().split(" ");
        nArray = new int[n];
        for (int i = 0; i < n; i++) {
            nArray[i] = Integer.parseInt(nA[i]);
        }
        Arrays.sort(nArray);
        int m = Integer.parseInt(in.readLine());
        String mA[] = in.readLine().split(" ");
        for (int i = 0; i < m; i++) {
            if (search(Integer.parseInt(mA[i]), n - 1)) {
                System.out.print("1 ");
            } else {
                System.out.print("0 ");
            }
        }

    }

    public static void main(String[] args) {
        try {
            new P10815().solve();
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
