import javax.swing.JApplet; 
import java.awt.*; 
import java.util.*; 
import java.text.DateFormat; 
 
public class MyClock extends java.applet.Applet implements Runnable { 
 
    Font f = new Font("Helvetica",Font.ITALIC, 12); 
    Calendar c; 
    Date d; 
    DateFormat df; 
    private Thread r; 
     
    public void start() { 
        if (r == null) { 
            r = new Thread(this, "Digital Clock"); 
            r.start(); 
        } 
    }
   
         public void stop() { 
        if (r != null) { 
            r = null; 
        }     } 
 
    public void run() { 
        Thread curr = Thread.currentThread(); 
        while(r == curr) { 
            repaint(); 
            try {r.sleep(1000);} 
            catch (InterruptedException e) {} 
        } 
    } 
 
    public void paint(Graphics g) 
    { 
        g.setColor(Color.red); 
        g.setFont(f); 
        c = Calendar.getInstance(); 
        d = c.getTime(); 
        df = DateFormat.getDateTimeInstance(DateFormat.FULL, 
DateFormat.FULL); 
        g.drawString(df.format(d), 25, 40); 
    } 
     
}