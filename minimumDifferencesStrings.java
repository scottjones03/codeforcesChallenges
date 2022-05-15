import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * MinimumDifferenceStrings
*/
public class MinimumDifferenceStrings {
    public static int[] stringToArray(int strLen, String test_case) {
        int[] arr = new int[strLen];
        int i = 0;
        for (char ch : test_case.toCharArray()) {
            arr[i]=(int)(Character.toLowerCase(ch))-96;
            i+=1;
        }
        return arr;
    }
    public static int solve(int n, int[] test_case) {
        return 0;
    }
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in); 
        int num_cases=input.nextInt(); 
        for (int i = 0; i < num_cases; i++) {
                int n =input.nextInt();
                int strLen = input.nextInt();
                int[][] options = new int[n][strLen];
                for (int j=0; j<n; j++) {
                    String option=input.next();
                    options[j] = stringToArray(strLen, option);
                }
                System.out.println(options[1][1]);
        }
        input.close();
    }
}
