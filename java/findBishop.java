package java;

import java.util.Arrays;
import java.util.Scanner;


public class findBishop {
    // bishop not on edges so always 2, 1, 2
    // ht_per_row = [1, 2, 2, 1, 2, 2, 1, 1]
    // ht_per_row = [2, 1, 2, 1, 1, 1, 1, 1]
    // ht_per_row = [2, 2, 2, 1, 2, 2, 2, 1]
    public static void main(String[] args) {
        int NUM_ROWS = 8;

        int t;
        String current_row;
        char current_char;
        int[] ht_per_row;
        int[] first_ht_pos;
        int row_index;
        int column_index;

        Scanner in = new Scanner(System.in);
        t = in.nextInt();

        for (int i = 0; i < t; i++) {
            ht_per_row = new int[NUM_ROWS];
            first_ht_pos = new int[NUM_ROWS];
            Arrays.fill(first_ht_pos, -1);
            for (int j = 0; j < NUM_ROWS; j++) {
                current_row = in.next();
                for (int j2 = 0; j2 < NUM_ROWS; j2++) {
                    current_char = current_row.charAt(j2);
                    if (current_char == '#') {
                        ht_per_row[j]++;
                        if (first_ht_pos[j]==-1) {
                            first_ht_pos[j] = j2;
                        }
                    }
                }
            }
            for (int j = 1; j < NUM_ROWS-1; j++) {
                if (ht_per_row[j]==1 && ht_per_row[j-1]==2 && ht_per_row[j+1] == 2) {
                    row_index = j+1;
                    column_index = first_ht_pos[j]+1;
                    System.out.printf("%d %d\n", row_index, column_index);
                }
            }
        }
        in.close();
    }
}
