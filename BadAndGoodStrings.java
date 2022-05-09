
import java.util.ArrayList;
import java.util.List;

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
    public static List<Integer> sorted(List<Integer> current_splitting) {
        // (a, b) -> (a+1, b-1)
        // OO -> EE, EE -> OO, OE -> EO, EO -> OE
        // OEO -> EOO -> EEE, OEEO -> EOEO -> EOOE -> EEEE
        // OEEEO -> EOEEO -> EOOOO -> EEEEE
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
                        } else if (prevType == 1 && currentLen > 0) {
                            current_splitting.set(i-2, current_splitting.get(i-2)+1);
                            current_splitting.set(i-1, current_splitting.get(i-1)-1);   
                        }
                        currentLen=1;
                    }
                }
                prevType = currentType;
            }
            if (isGood(current_splitting)) {
                return current_splitting;
            } else {
                System.out.println(current_splitting);
            }
        }
        return current_splitting;
    }
    public static void main(String[] args) {
        String test_case = "000001110010100111110";
        System.out.println(divider(test_case));
        System.out.println(sorted(divider(test_case)));
    }
}