import java.util.Scanner;

/**
 * SubtleSubstringGame
*/
public class subtleSubstringGame {
    public static int stringToScore(String test_case) {
        int i = 0;
        for (char ch : test_case.toCharArray()) {
            i+=(int)(Character.toLowerCase(ch))-96;
        }
        return i;
    }
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in); 
        int num_cases=input.nextInt(); 
        for (int i = 0; i < num_cases; i++) {
                String game = input.next();
                int alice_score = 0;
                int bob_score = 0;
                int frontSubScore;
                in backSubScore;
                while (game.length() > 0) {
                    if (game.length() % 2 == 0) {
                        alice_score+=stringToScore(game);
                        game = "";
                    } else {
                        frontSubScore=stringToScore(game[0::game.length()-1]);
                        backSubScore=stringToScore(game[1::game.length()]);
                        if (frontSubScore >= backSubScore ) {
                            game = Character.toString(game[game.length()-1]);
                            alice_score+=frontSubScore;
                        } else {
                            game = Character.toString(game[0]);
                            alice_score+=backSubScore;
                    }
                    
                    if ((game.length()+1) % 2 == 0) {
                        bob_score+=stringToScore(game);
                        game = "";
                    } else {
                        if (game

                System.out.println(minDiff);
        }
        input.close();
    }
}