package S15000.S15900;

import java.util.Scanner;

// 15947 아기 석환 뚜루루 뚜루
public class P15947 {
	final static String SONG[] = { "baby", "sukhwan ", "tururu", "turu", "very", "cute", "tururu", "turu", "in", "bed",
			"tururu", "turu", "baby", "sukhwan" };

	public void solve() {
		Scanner sc = new Scanner(System.in);
		int n;
		n = sc.nextInt();
		int re = (n) / 14;
		if (n % 14 != 0 && n % 14 % 4 == 0) {
			if (re < 4) {
				System.out.print(SONG[3]);
				for (int i = 0; i < re; i++) {
					System.out.print("ru");
				}
			} else {
				System.out.print("tu+ru*" + (re + 1));
			}
		} else if (n % 14 % 4 == 3) {
			if (re < 3) {
				System.out.print(SONG[2]);
				for (int i = 0; i < re; i++) {
					System.out.print("ru");
				}
			} else {
				System.out.print("tu+ru*" + (re + 2));
			}
		} else {
			System.out.print(SONG[(n-1) % 14 ]);
		}

	}

	public static void main(String args[]) {
		new P15947().solve();
	}
}
