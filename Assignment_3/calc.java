import java.util.Arrays;

public class calc{
  public static void main(String [] args){

    String [] strArr = args[0].split(" ");
    String expr = strArr[0] + " " + strArr[1] + " " + strArr[2];
    //int int1 = Integer.parseInt(strArr[0]);
    float int1 = Float.parseFloat(strArr[0]);
    //int int2 = Integer.parseInt(strArr[2]);
    float int2 = Float.parseFloat(strArr[2]);
    float out;

    if(strArr[1].equals("+")) {
      out = int1 + int2;
    }else if(strArr[1].equals("-")) {
      out = int1 - int2;
    }else if(strArr[1].equals("*")) {
      out = int1 * int2;
    }else {
      out = int1 / int2;
    }
    //System.out.println(expr + " = " + Integer.toString(out));
    System.out.println(expr + " = " + Float.toString(out));
  }
}
