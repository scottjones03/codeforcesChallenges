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
        String game;
        int alice_score;
        int bob_score;
        int frontSubScore;
        int backSubScore;
        for (int i = 0; i < num_cases; i++) {
                game = input.next();
                alice_score = 0;
                bob_score = 0;
                while (game.length() > 0) {
                    if (game.length() % 2 == 0) {
                        alice_score+=stringToScore(game);
                        game = "";
                    } else if (game.length() > 1) {
                        frontSubScore=stringToScore(game.substring(0,game.length()-1));
                        backSubScore=stringToScore(game.substring(1, game.length()));
                        if (frontSubScore >= backSubScore ) {
                            game = game.substring(game.length()-1);
                            alice_score+=frontSubScore;
                        } else {
                            game = game.substring(0, 1);
                            alice_score+=backSubScore;
                        }
                    }
                    
                    if ((game.length()+1) % 2 == 0) {
                        bob_score+=stringToScore(game);
                        game = "";
                    } else if (game.length() > 1) {
                        frontSubScore=stringToScore(game.substring(0, game.length()-1));
                        backSubScore=stringToScore(game.substring(1, game.length()));
                        if (frontSubScore >= backSubScore ) {
                            game = game.substring(game.length()-1);
                            bob_score+=frontSubScore;
                        } else {
                            game = game.substring(0, 1);
                            bob_score+=backSubScore;
                        }
                    }
                        
                }
                if (alice_score > bob_score) {
                    System.out.println("Alice " + (alice_score-bob_score));
                } else {
                    System.out.println("Bob " + (bob_score-alice_score));
                }

        }
        input.close();
    }
}
