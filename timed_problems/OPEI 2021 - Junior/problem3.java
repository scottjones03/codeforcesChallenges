import java.util.Arrays;
import java.util.Scanner;

/**
 * problem3
 * O -> e -> S -> e -> L -> e -> N
 */
public class problem3 {
    public static void main(String[] args) {
        new solve_problem(args);
    }
}
class solve_problem {
    public class Tuple<K, V> {
        private K first;
        private V second;
    
        public Tuple(K first, V second) {
            this.first=first;
            this.second=second;
        }
    }

    public static char turn_left(char current_orientation) {
        if (current_orientation == 'O') {
            return 'S';
        } else if (current_orientation == 'S') {
            return 'L';
        } else if (current_orientation == 'L') {
            return 'N';
        } else if (current_orientation == 'N') {
            return 'O';
        } 
        System.err.println("Input Error");
        return current_orientation;
    }

    public static char turn_right(char current_orientation) {
        if (current_orientation == 'O') {
            return 'N';
        } else if (current_orientation == 'S') {
            return 'O';
        } else if (current_orientation == 'L') {
            return 'S';
        } else if (current_orientation == 'N') {
            return 'L';
        } 
        System.err.println("Input Error");
        return current_orientation;
    }
    public static int[] move_forward(int[] current_coords, char current_orientation) {
        if (current_orientation == 'O') {
            current_coords[0]-=1;
        } else if (current_orientation == 'S') {
            current_coords[1]-=1;
        } else if (current_orientation == 'L') {
            current_coords[0]+=1;
        } else if (current_orientation == 'N') {
            current_coords[1]+=1;
        } else {
            System.err.println("Input Error");
        }
        return current_coords;
    }
    public Tuple<int[], Character> run_command(char command, int[] current_coords, char current_orientation) {
        int[] new_coords = Arrays.copyOf(current_coords, 2);
        char new_orientation = current_orientation;
        if (command == 'E') {
            new_orientation=turn_left(new_orientation);
        } else if (command == 'D') {
            new_orientation=turn_right(new_orientation);
        } else {
            new_coords=move_forward(new_coords, new_orientation);
        }
        Tuple<int[], Character>  out = this.new Tuple<>(new_coords, new_orientation);
        return out;
    }

    public static Boolean in_dont_go_coords(int[] current_coords, int[][] dont_go_coords, int dont_go_length) {
        for (int i=0; i<dont_go_length; i++) {
            if (Arrays.equals(dont_go_coords[i], current_coords)) {
                return true;
            }
        }
        return false;
    }
    public static Boolean is_lost(int[] current_coords, int[] left_coords, int[] right_coords) {
        return (
            left_coords[0]>current_coords[0] || 
            left_coords[1]>current_coords[1] || 
            right_coords[0]<current_coords[0] || 
            right_coords[1]<current_coords[1]
        );
    }
    public solve_problem(String[] args) {
        Scanner input = new Scanner(System.in);

        int[] right_coords = {input.nextInt(), input.nextInt()};
        int[] left_coords = {0, 0};

        int num_robots = input.nextInt();

        int[][] dont_go_coords = new int[num_robots+1][2];
        int dont_go_length = 0;

        for (int i = 0; i < num_robots; i++) {
            Boolean is_lost = false;

            int[] robot_coords = {input.nextInt(), input.nextInt()};
            char robot_orientation = input.next().charAt(0);
            String commands = input.next();

            for (char command : commands.toCharArray()) {
                Tuple<int[], Character> result = run_command(command, robot_coords, robot_orientation);
                if (in_dont_go_coords(result.first, dont_go_coords, dont_go_length)==false) {
                    is_lost = is_lost(result.first, left_coords, right_coords);
                    if (is_lost==false) {
                        robot_coords=Arrays.copyOf(result.first, 2);
                        robot_orientation=result.second;
                    } else {
                        dont_go_coords[dont_go_length] = Arrays.copyOf(result.first, 2);
                        dont_go_length+=1;
                        break;
                    }
                } 
            }

            if (is_lost) {
                System.out.printf("%d %d %c PERDIDO\n", robot_coords[0], robot_coords[1], robot_orientation);
            } else {
                System.out.printf("%d %d %c\n", robot_coords[0], robot_coords[1], robot_orientation);
            }
        }
        input.close();
    }
}
