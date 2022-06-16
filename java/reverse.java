package java;

import java.util.Scanner;

public class reverse {
// 
//     reverse subsegment from
//     p1, p2, ..., pl-1, pl, ..., pr-1, pr, pr+1, ... , pn
//     to
//     p1, p2, ..., pl-1, pr, pr-1, ..., pl, pr+1, ... , pn
//     find lexicographically smallest permutation
//     => a is smaller than b if first positions differ and 
//     a has smallest first position element.
//     Permutation has n distinct integers
//     => from 1 to n in any order
        
//     solution:
//     pick where 1 is and swap with first
//     OR if 1 in first, put 2 in second and so on.
//

    public static int[] do_swap(int n, int[] a, int l, int r) {
        int[] copy = new int[n];
        for (int i = 0; i < n; i++) {
            if (i < l || i > r) {
                copy[i] = a[i];
            } else {
                // int idx1 = r - i;
                // int idx2 = i - l;
                // idx2 = 0, then a[r], 1 then a[r-1], r-1 then a[l+1]
                // diff is r, r-2, r-4, ..., r-l-2, r-l
                // diff = r-2*idx2, aIdx = idx2 + r -2*idx2 = r - idx2
                //  aIdxc = r+l-i
                copy[i] = a[r+l-i];
            }
        }
        return copy;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int j = 0; j < a.length; j++) {
                a[j] = in.nextInt();
            }
            int l=0;
            int r=0;
            for (int j = 1; j < a.length+1; j++) {
                if (a[j-1]!=j) {
                    l = j-1;
                    for (int k = 0; k < a.length; k++) {
                        if (a[k]==j) {
                            r = k;
                            break;
                        }
                    }
                    break;
                }
            }
            int[] out = do_swap(n, a, l, r);
            for (int x : out) {
                System.out.printf("%d ", x);
            }
            System.out.println();

        }
        in.close();
    }
}
