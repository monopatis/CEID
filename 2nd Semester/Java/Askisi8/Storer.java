public class Storer extends Thread { 
    private Locker l; 
    private int n; 
 
    public Storer(Locker l, int n) { 
        this.l = l; 
        this.n = n; 
    } 
 
    public void run() { 
        for (int i = 0; i < 10; i++) { 
            l.put(i); 
            System.out.println("Storer no." + n + " stored thing no." + i 
+ " into the locker."); 
            try { 
                sleep((int)(Math.random() * 500)+100); 
            } catch (InterruptedException e) { } 
        } 
    } 
}