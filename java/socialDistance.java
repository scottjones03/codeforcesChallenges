package java;

import java.util.Arrays;
import java.util.Scanner;

public class socialDistance {
    // m chairs in circle , n want to sit
    // i want atleast a[i] on right and left

    // for n=3, m=2, n>m so no
    // for n=2, m=4, each person wants 1 space
    // p1 in 0 -> 3 is free, 1 is free 
    // p2 in 2 -> 1 iz free, 3 is free
    // for n=2, m=5, p=2 1
    // p1 in 0 -> 4, 3, 1,2 free 
    // p2 in none so no
    // need to make it so the spaciing is shared as much
    // as possible

    // order p array and make it so each adjacent p is next to the other
    public static Boolean enough_spaces(long[] arr, long m, int n) {
        Arrays.sort(arr);
        // sit the n-1 th person first
        // free, ..., free, n-1 sit, free, ..., free, n-2 sit
        long sum_taken=arr[n-1]+1;
        for (int j = n-2; j >= 0; j--) {
            sum_taken+=arr[j+1]+1;
            if (sum_taken>m) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        for (int i = 0; i < t; i++) {
            int n = input.nextInt();
            long m = input.nextLong();
            long[] arr = new long[n];
            for (int j = 0; j < n; j++) {
                arr[j] = input.nextLong();
            }
            if (enough_spaces(arr, m, n)) {
                System.out.printf("YES\n");
            } else {
                System.out.printf("NO\n");
            }
            
        }
        input.close();
    }
}
