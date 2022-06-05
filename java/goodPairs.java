package java;

import java.util.Scanner;

public class goodPairs {
    // good pair: |ai-ak| + |aj-ak| = |ai-aj|
    // ie either (ai-ak) - (aj-ak) = (ai-aj)
    // -> implies ai>=ak, ak>=aj, ai>=ak>=aj
    // or -(ai-ak)+(aj-ak) = -(ai-aj)
    // -> implies ak>=ai, aj>=ak, aj>=ai, aj>=ak>=ai
    // for all 1<=k<=n
    // 1 2 3 4 , then ai = 1, aj = 4 works for all ak = 1, 2, 3, 4
    // whereas ai = 2, aj = 4, doesn't work for ak=1
    // and ai = 1, aj = 3 doesn't work for ak = 4
    // but ai = 4, aj = 1 works for all ak
    //  so must be max min or min max

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        for (int i = 0; i < t; i++) {
            int n = input.nextInt();
            int[] a = new int[n];
            int min_idx = 0;
            int max_idx = 0;
            for (int j = 0; j < n; j++) {
                a[j] = input.nextInt();
                if (a[j]>=a[max_idx]) {
                    max_idx = j;
                } 
                if (a[j]<=a[min_idx]) {
                    min_idx=j;
                }
            }
            System.out.printf("%d %d\n", min_idx+1, max_idx+1);
        }
        input.close();
    }
}
