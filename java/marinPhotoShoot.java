package java;

import java.util.Scanner;

public class marinPhotoShoot {
    // every segment in line must have so number of males <= number of females for any segment
    // n in total, male = 0  and female=1
    // can add players to line but not remove, need to know minimum amount to add

    //  000 -> 1010101, 001 -> 10101, 010 -> 0110, 011 -> 011
    // ie line of 0x needs 1 for all x
    //  line of 00x needs 2 for all x (0110)
    //  lines 000x needs 4 (0110110x)
    //  lines 0000x needs 6 (0110110110) (or 101010101 5 this is false)

    // could just go through line many times, adding 0 until satisfied
    // better : when you see 00 add 11 inbetween, ie 0110, or 010 add 1, ignore edges
    // 1010110000100000101 -> 101(1)0110(11)0(11)0(11)01(1)0(11)0(11)0(11)0(11)01(1)01

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        for (int i = 0; i < t; i++) {
            int n = input.nextInt();
            // needed to finish off line
            input.nextLine();
            String s = input.nextLine();
            int current_item;
            int next_item;
            int next_next_item;
            int count=0;
            for (int j = 0; j < n-1; j++) {
                current_item=Character.getNumericValue(s.charAt(j));
                if (current_item==0) {
                    next_item=Character.getNumericValue(s.charAt(j+1));
                    if (next_item==0) {
                        count+=2;
                    } else {
                        if (j+2<n) {
                            next_next_item=Character.getNumericValue(s.charAt(j+2));
                            if (next_next_item==0) {
                                count+=1;
                            } else {
                                count+=0;
                            }
                        } else {
                            count+=0;
                        }
                    }
                } else {
                    count+=0;
                }
            }
            System.out.println(count);
        }
        input.close();
    }
}
