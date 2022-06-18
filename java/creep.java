import java.util.Scanner;
 
public class BinaryCreepiness {
     public static void main(String[] args) {
          Scanner in = new Scanner(System.in);
          int t=in.nextInt();
          for (int i=0; i<t; i++) {
               int z=in.nextInt();
               int o=in.nextInt();
               if (z > o) {
                    for (int j=0; j<o; j++) {
                         System.out.printf("01");
                    }
                    for (int j=0; j<z-o; j++) {
                         System.out.printf("0");
                    }
               } else {
                    for (int j=0; j<z; j++) {
                         System.out.printf("10");
                    }
                    for (int j=0; j<o-z; j++) {
                         System.out.printf("1");
                    }
               }
              
               System.out.printf("\n");
          }
          in.close();
     }
}
