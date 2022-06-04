package java;

import java.util.Scanner;

public class gcdLCM {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int t = input.nextInt();
        for (int i = 0; i < t; i++) {
            int n = input.nextInt();
            System.out.printf("%d %d %d %d\n", n-3, 1, 1, 1);
        }
        input.close();
    }
}
