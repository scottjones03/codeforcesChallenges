package java;

import java.util.Scanner;

public class plusOneSubset {
    // wants arr of ints a1=a2=a3=...=an
    // operation: take some indices and inc by 1

    // want minimum number of operations

    // upper bound = amax-amin, ie add to every element until 
    // they equal amax, amin needs max need operating on the most = amax-amin times
    // this is the minimum number of operations if amax isn't changed

    // If we instead could change amax, it could only increase or stay same.
    // so the distance between amin and amax could only increase or stay same.
    // since amin=amax at end, number of operations can only increase or stay same.

    // min operations = amax-amin
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        for (int i = 0; i < t; i++) {
            int n = input.nextInt();
            long min_a=(long) Math.pow(10.0, 9.0);
            long max_a=0;
            long current_a;
            for (int j = 0; j < n; j++) {
                current_a = input.nextLong();
                if (current_a>=max_a) {
                    max_a=current_a;
                }
                if (current_a<=min_a) {
                    min_a=current_a;
                }
            }
            System.out.println(max_a-min_a);

        }
        input.close();
    }
}
