import java.io.*;

public class Main
{
    public static void main(String args[])
    {
        int a,p=0;
        try{
            File f1 = new File("src.txt");
            boolean find = f1.exists();
            FileInputStream fis = new FileInputStream("src.txt");
            if (find){
                System.out.println("To arxeio uparxei!");}
            }
            catch (FileNotFoundException e) {
                System.out.println("File not found");}
        
        try {         
            File f1 = new File("src.txt");
            File f2 = new File("dest.txt");
            
            FileReader fin = new FileReader(f1);
            FileWriter fout = new FileWriter(f2);
            
            System.out.println("Prin");
            System.out.println("--------------------------");
            System.out.println("Megethos Source = " + f1.length());
            System.out.println("Megethos Dest = " + f2.length());           
        
            do
            {
                a = fin.read();
                if (a != -1)
                {
                    if ((char)a == ' ')
                    {
                        a = (int)'@';
                        p++;
                    }
                    fout.write(a);
                }
            } while (a != -1);
            fin.close();
            fout.close();
            System.out.println("--------------------------");
            System.out.println("Meta");
            System.out.println("--------------------------");
            System.out.println("Megethos Source = " + f1.length());
            System.out.println("Megethos Dest = " + f2.length());
            System.out.println("Pli8os kenwn pou antikatasta8ikan: " + p);
        } catch(FileNotFoundException fnfe) {
            System.exit(0);
        } catch(IOException ioe) {
            System.out.println("IO error.");
            System.exit(0);
        }        
    }
}