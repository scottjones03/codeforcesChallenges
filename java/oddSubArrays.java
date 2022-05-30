package java;

import java.util.Scanner;

/**
 * oddSubArrays
*/
public class oddSubArrays {
    public static int[] take_slice(int[] arr, int start, int end) {
        int[] sliced_arr = new int[end-start];
        for (int i=start; i<end; i++) {
            sliced_arr[i-start] = arr[i];
        }
        return sliced_arr;
    }
    
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in); 
        int num_cases=input.nextInt(); 
        for (int i = 0; i < num_cases; i++) {
            int test_case_length =input.nextInt();
            int[] test_case = new int[test_case_length];
            for (int j =0; j< test_case_length; j++) {
                test_case[j] = input.nextInt();
            }
            int num_odd_arrs=0;
            int current_split=0;
            int current_max = 0;
            for (int j=0; j< test_case_length; j++) {
                if (test_case[j]>current_max) {
                    current_max=test_case[j];
                    continue;
                } else {
                    for (int k=current_split; k< j; k++) {
                        // System.out.print(j+" "+test_case[k]+" "+test_case[j] +"\n");
                        if (test_case[k] > test_case[j]) {
                            current_split=j+1;
                            num_odd_arrs+=1;
                            current_max=0;
                            // System.out.print(current_split+ " and" + num_odd_arrs + "\n");
                            break;
                        }
                    }
                }
            } 
            System.out.println(num_odd_arrs);  
        }
        input.close();
    }
}