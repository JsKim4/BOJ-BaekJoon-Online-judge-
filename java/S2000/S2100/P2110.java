package S2000.S2100;

import java.util.Arrays;
import java.util.Scanner;

public class P2110 {
	int temp[] = new int[200001];
	static int arr[];
	public boolean search(int count,int len) {
		int snum=arr[0];
		int index=0;
		while(--count!=0) {
			index=compare(index+1,arr.length-1,snum+len);
			//System.out.println("search index : "+index+"   len : "+(snum+len));
			if(index==-1)
				return false;
			if(arr.length-index<count)
				return false;
			snum=arr[index];
		}
		return true;
	}

	public int compare(int left, int right, int snum) {
		if(arr[right]<snum)
			return -1;
		int mid = (left + right) / 2;
		
		if (mid == left) {
			if (arr[left] >= snum)
				return left;
			return right;
		}
		if (arr[mid] == snum) {
			return mid;
		} else if (arr[mid] > snum) {
			return compare(left, mid, snum);
		} else {
			return compare(mid, right, snum);
		}
	}

	public static void main(String args[]) {
		int n = 0, m = 0;
		P2110 p = new P2110();
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		Arrays.sort(arr);
		int minLen = 1;
		int len = arr[arr.length-1] - arr[0];
		int maxLen = arr[arr.length-1] - arr[0];
		while(true) {
			//System.out.println(len+" "+maxLen+" "+minLen);
			if(p.search(m,maxLen)) {
				minLen = maxLen;
				maxLen = (maxLen+len)/2;
				//System.out.println("1");
				
			}else {
				len = maxLen;
				maxLen = (maxLen+minLen)/2;
				//System.out.println("2");
			}
			if(maxLen == minLen) {
				break;
			}
		}
		System.out.println(maxLen);
	}
}
