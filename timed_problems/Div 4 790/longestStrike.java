import java.util.Arrays;
import java.util.Scanner;

/**
 * longestStrike
 */
public class longestStrike {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        for (int i = 0; i < t; i++) {
            int n = input.nextInt();
            int k = input.nextInt();
            int[] arr = new int[n];
            int[][] unique_arr = new int[n][2];

            for (int j = 0; j < n; j++) {
                arr[j] = input.nextInt();
                for (int j2 = 0; j2 < n; k++) {
                    if (unique_arr[j2][1]==0) {
                        unique_arr[j2][0]=arr[j];
                        unique_arr[j2][1]=1;
                        break;
                    } else if (unique_arr[j2][0]==arr[j]) {
                        unique_arr[j2][1]+=1;
                        break;
                    }
                }
            }
            Arrays.sort(arr);
            int l=-1;
            int r=-1;
            Boolean is_valid=false;
            for (int lIdx = 0; lIdx < n; lIdx++) {
                for (int rIdx = n-1; rIdx>=lIdx; rIdx--) {
                    l = arr[lIdx];
                    r = arr[rIdx];
                    is_valid=true;
                    for (int[] js : unique_arr) {
                        if (js[1]==0) {
                            is_valid=false; 
                            break;
                        }
                        else if (l<=js[0] && js[0]<=r && js[1]<k) {
                            is_valid=false;
                            break;
                        }
                    }
                    if (is_valid) {
                        break;
                    }
                }
                if (is_valid) {
                    break;
                }
            }
            if (l==-1) {
                System.out.println(-1);
            } else if (is_valid==false) {
                System.out.println(-1);
            } else {
                System.out.printf("%d %d\n", l, r);
            }
        }
        input.close();
    }
}