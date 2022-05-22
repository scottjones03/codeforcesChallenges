// y = (b ^ a) * x 
// a = log_b y/x, b = (y/x) ^ (1/a)


import java.util.Scanner;

/**
 * numberTransformation
 */
public class numberTransformation {
    public static int[] findAB(Scanner in, int y, int x) {
        int b;
        float calc;
        int a = 50;
        for (int i = 1; i < 8; i++) {
            calc = (y/x) ^ (1/a);
            if calc < 1;
                a += 50 ^ (-i)
        }
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int test_cases = in.nextInt();
        for (int i = 0; i < test_cases; i++) {
            ...
        }
    }
}