package java;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * BadAndGoodStrings
*/
public class BadAndGoodStrings {
    public static List<Integer> divider(String test_case) {
        List<Integer> res = new ArrayList<>();
        int current = -1;
        int currentLen = 0;
        for (char item: test_case.toCharArray()) {
            int value = Character.getNumericValue(item);
            if (current == -1) {
                current = value;
                currentLen += 1;
            } else if (value == 1 || value == 0) {
                if (value == current) {
                    currentLen += 1;
                } else {
                    current = value;
                    res.add(currentLen);
                    currentLen = 1;
                }    
            } else {
                System.out.println(item + " " + value);
                throw new IllegalArgumentException(test_case);
            }
        }
        return res;
    }
    public static boolean isGood(List<Integer> current_splitting) {
        for (Integer integer : current_splitting) {
            if (integer % 2 != 0) {
                return false;
            }
        }
        return true;
    }
    public static int sorted(List<Integer> current_splitting) {
        // (a, b) -> (a+1, b-1)
        // OO -> EE, EE -> OO, OE -> EO, EO -> OE
        // OEO -> EOO -> EEE, OEEO -> EOEO -> EOOE -> EEEE
        // OEEEO -> EOEEO -> EOOOO -> EEEEE
        int number_of_swaps = 0;
        for (int k = 0; k < 20; k++) {
            int currentLen = 0;
            // Even = 0, Odd = 1
            int prevType = -1;
            for (int i = 0; i < current_splitting.size(); i++) {
                int item = current_splitting.get(i);
                int currentType = item % 2;
                if (prevType == -1) {
                    currentLen += 1;
                } else {
                    if (prevType == currentType) {
                        currentLen+=1;
                    } else {
                        if (currentLen % 2 != 0) {
                            int prevItem = current_splitting.get(i-1);
                            if (item!=0) {
                                current_splitting.set(i-1, prevItem+1);
                                current_splitting.set(i, item-1);
                            } else {
                                current_splitting.set(i-1, prevItem-1);
                                current_splitting.set(i, item+1);
                            }
                            number_of_swaps+=2;
                        } else if (prevType == 1 && currentLen > 0) {
                            current_splitting.set(i-2, current_splitting.get(i-2)+1);
                            current_splitting.set(i-1, current_splitting.get(i-1)-1);  
                            number_of_swaps+=2;
                        }
                        currentLen=1;
                    }
                }
                prevType = currentType;
            }
            if (isGood(current_splitting)) {
                System.out.println(current_splitting);
                return number_of_swaps;
            } else {
                System.out.println(current_splitting);
            }
        }
        return number_of_swaps;
    }

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