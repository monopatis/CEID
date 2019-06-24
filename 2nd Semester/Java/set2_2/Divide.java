import java.io.*;

public class Divide
{
    public static void main(String args[])
    {
       System.out.println("Dwste ton 1o akeraio:");
       int a = readInt();
       System.out.println("Dwste ton 2o akeraio:");
       int b = readInt();
       try {
            System.out.println(a + "/" + b + "=" + a/b);
        } catch(ArithmeticException ae) {
            System.out.println("Divider can't be zero.");
        }
    }
    
    public static int readInt() {
        byte b[] = new byte[16];
        String str;
        try {   
            System.in.read(b);
            str = (new String(b)).trim();
            return Integer.parseInt(str);
        } catch (IOException e) {
            System.out.println("Exception: " + e.toString());
            return 0;
        } catch (NumberFormatException e) {
            System.out.println("Exception: " + e.toString() + "\nReturned value: -1");
            return -1;
        }
    }
}