public class Calculator {
  public static void main(String [] args) {

    String[] input = String.split(args[0]);
    int int1 = Integer.parseInt(input[0]);
    int int2 = Integer.parseInt(input[2]);
    int out;

    if(input[1].equals("+")) {
      out = int1 + int2;
    }else if(input[1].equals("-")) {
      out = int1 - int2;
    }else if(input[1].equals("*")) {
      out = int1 * int2;
    }else {
      out = int1 / int2;
    }
    System.out.println(out);
  }
}
