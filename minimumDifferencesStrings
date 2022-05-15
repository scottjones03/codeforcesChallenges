import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * MinimumDifferenceStrings
*/
public class MinimumDifferenceStrings {
    public static int[] stringToArray(String test_case) {
        int[] arr = new int[test_case.length()];
        int i = 0;
        for (char ch : test_case.toCharArray()) {
            arr[i]=Character.getNumericValue(ch);
            i+=1;
        }
        return arr;
    }
    public static int solve(int n, int[] test_case) {
        int swaps = 0;
        int group_length = 1;
        for (int i = 1; i < n; i++) {
            if (test_case[i-1] == test_case[i]) {
                group_length+=1;
            }
            else if (group_length % 2 != 0) {
                test_case[i]=test_case[i-1];
                swaps+=1;
                group_length=0;
            }
            else {
                group_length=1;
            }
        }
        return swaps;
    }
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in); 
        int num_cases=input.nextInt(); 
        for (int i = 0; i < num_cases-1; i++) {
                int n =input.nextInt();
                String test_case=input.next();
                int[] test_arr = stringToArray(test_case);
                System.out.println(solve(n, test_arr));
        }
        int n =input.nextInt();
        String test_case=input.next();
        int[] test_arr = stringToArray(test_case);
        System.out.print(solve(n, test_arr));
        input.close();
    }
}
