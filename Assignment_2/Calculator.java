//import java util.*;
import java.util.Scanner;

public class Test{
  public static void main(String [] args){

    //String input = "1+4";
    Scanner in = new Scanner(System.in);
    System.out.println("Enter an expression\n");
    String input = in.nextLine();
    String [] strArr = input.split("", 0);
    int int1 = Integer.parseInt(strArr[0]);
    int int2 = Integer.parseInt(strArr[2]);
    int out;

    if(strArr[1].equals("+")) {
      out = int1 + int2;
    }else if(strArr[1].equals("-")) {
      out = int1 - int2;
    }else if(strArr[1].equals("*")) {
      out = int1 * int2;
    }else {
      out = int1 / int2;
    }
    System.out.println(input + " " + out);


  }
}
