
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * cardsShuffle
*/
public class cardsShuffle {
    public static int[] take_slice(int[] arr, int start, int end) {
        int[] sliced_arr = new int[end-start];
        for (int i=start; i<end; i++) {
            sliced_arr[i-start] = arr[start];
        }
        return sliced_arr;
    }
    public static int[] shuffle_cards(int[] cards, int b) {
        int[] front_cards = take_slice(cards, 0, b);
        for (int i=0; i<cards.length-b; i++) {
            cards[i] = cards[i+b];
        }
        for (int i=cards.length-b; i<cards.length; i++) {
            cards[i] = front_cards[i-(cards.length-b)];
        }
        return cards;
    }
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in); 
        int num_cases=input.nextInt(); 
        for (int i = 0; i < num_cases; i++) {
                int num_cards =input.nextInt();
                int[] cards = new int[num_cards];
                for (int j =0; j< num_cards; j++) {
                    cards[j] = input.nextInt();
                }
                int num_shuffles = input.nextInt();
                for (int j=0; j<num_shuffles; j++) {
                    int b = input.nextInt();
                    cards = shuffle_cards(cards, b);
                }
                System.out.println(cards[0]);
        }
    }
}