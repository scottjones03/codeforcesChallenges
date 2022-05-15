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
    public static int calculateDiff(int strLen, int[] w1, int[] w2) {
        int diff=0;
        for (int i=0; i<strLen; i++) {
            diff+=Math.abs(w1[i]-w2[i]);
        }
        return diff;
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
                int minDiff = 26*strLen;
                int diff;
                for (int p=0; p<n-1; p++) {
                    for (int q=p+1; q<n; q++) {
                        diff = calculateDiff(strLen, options[p], options[q]);
                        if (diff < minDiff) {
                            minDiff=diff;
                        }
                    }
                }
                System.out.println(minDiff);
        }
        input.close();
    }
}
