
import java.util.Scanner;
/**
 * robots
 */
public class robots {
    public static int[][] find_robots(Scanner in, int n, int m) {
        String row;
        int[][] leftRowColRobots = new int[2][2];
        boolean firstRobot = true;
        for (int i = 0; i < n; i++) {
            row=in.next();
            for (int j = 0; j < m; j++) {
                char cell=row.charAt(j);
                if (cell=='R') {
                    int[] idx = {i, j};
                    if (firstRobot) {
                        leftRowColRobots[0]=idx;
                        leftRowColRobots[1]=idx;
                        firstRobot=false;
                    }
                    else {
                        // Check for leftmost row robot.
                        if (leftRowColRobots[0][0]>idx[0]) {
                            leftRowColRobots[0]=idx;
                        }
                        // Check for leftmost column robot.
                        if (leftRowColRobots[1][1]>idx[1]) {
                            leftRowColRobots[1]=idx;
                        }
                    }
                }
            }
        }
        return leftRowColRobots;
    }
    public static boolean case_verdict(Scanner in) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] leftRowColRobots = find_robots(in, n, m);
        if ((leftRowColRobots[0][0] == leftRowColRobots[1][0]) || (leftRowColRobots[0][1] == leftRowColRobots[1][1])) {
            return true;
        } 
        else {
            return false;
        }
        
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int test_case = input.nextInt();
        for (int i = 0; i < test_case; i++) {
            if (case_verdict(input)) {
                System.out.println("YES");
            }
            else {
                System.out.println("NO");
            }
        }


    }
}