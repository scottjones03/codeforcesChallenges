// y = (b ^ a) * x 
// a = log_b y/x, b = (y/x) ^ (1/a)


import java.util.Scanner;

/**
 * numberTransformation
 */
public class numberTransformation {
    public static int[] findAB(int x, int y) {
        int a;
        float calc;
        int[] out = {0, 0};
        if (y % x == 0) {
            if (y/x <= 10e9) {
                out[0] = 1;
                out[1] = y/x;
                return out;
            } else {
                for (int i = 2; i < y/x; i++) {
                    a=0;
                    calc = y/x;
                    while (calc % i == 0) {
                        calc = calc / i;
                        a+=1;
                        if (calc == 1) {
                            out[0] = a;
                            out[1] = i;
                            return out;
                        }
                    }
                }
            }
        }
        return out;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int test_cases = in.nextInt();
        for (int i = 0; i < test_cases; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            int[] res = findAB(x, y);
            System.out.println(res[0] + " " + res[1]);
        }
        in.close();
    }
}