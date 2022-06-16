
import java.util.Scanner;

public class problem4 {
    // 5,6,3,2 W, B, W, B
    // if k=11, then take 3 and turn to B 
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        for (int i = 0; i < t; i++) {
            int n = input.nextInt();
            int k = input.nextInt(); 
            String stripe_str = input.nextLine();
            int[][] stripe = new int[n][2];
            int max_blength=0;
            int current_blength=0;
            int current_wlength=0;
            int stripe_idx=0;
            for (int j = 0; j < n; j++) {
                if (stripe_str.charAt(j)=='B') {
                    current_blength+=1;
                    stripe[stripe_idx][0] = 0;
                    stripe[stripe_idx][1] = current_wlength;
                    current_wlength=0;
                } else {
                    current_wlength+=1;
                    if (current_blength>max_blength) {
                        max_blength=current_blength;
                    }
                    stripe[stripe_idx][0] = 1;
                    stripe[stripe_idx][1] = current_blength;
                    current_blength=0;
                }
            }
            if (max_blength>=k) {
                System.out.println(0);
            } else {
                int[] combinations_swaps;
                int[] combinations_lengths; 
                for
            }

            
        }
        input.close();
    }
}
