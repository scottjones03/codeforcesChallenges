package java;
import java.util.Scanner;
 
 
/**
 * profSlim
*/
public class profSlim {
    public static Boolean is_sorted(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            if (arr[i]<arr[i-1]) {
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
            int[] arr = new int[n];
            for (int j = 0; j < arr.length; j++) {
                arr[j] = input.nextInt();
            }
            for (int j = 0; j < arr.length; j++) {
                if (arr[j] > 0) {
                    for (int k = j+1; k < arr.length; k++) {
                        if (arr[k] < 0) {
                            arr[j] *= -1;
                            arr[k] *= -1;
                            break;
                        }
                    }
                }
            }
            if (is_sorted(arr)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
            
        }
        input.close();
 
    }
}
