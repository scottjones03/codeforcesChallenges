import java.util.Scanner;

public class ArithmeticMean {
     public static void main(String[] args) {
          Scanner in = new Scanner(System.in);
          int t = in.nextInt();
          for (int i=0; i<t; i++) {
               int a1=in.nextInt();
               int a2=in.nextInt();
               int a3=in.nextInt();
               if ((a1+a3-2*a2)%3==0) {
                    System.out.println(0);
               } else {
                    System.out.println(1);
               }
               
               
          }
     }
}
