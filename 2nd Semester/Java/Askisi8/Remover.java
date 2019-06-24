public class Remover extends Thread { 
    private Locker l; 
    private int n;  
    public Remover(Locker l, int n) { 
        this.l = l; 
        this.n = n; 
    } 
 
    public void run() { 
        int x = 0; 
        for (int i = 0; i < 10; i++) { 
            x = l.get(); 
            System.out.println("Remover no." + n + " took the thing no." + 
x + " from the locker."); 
            try { 
                sleep((int)(Math.random() * 500)+100); 
            } catch (InterruptedException e) { } 
        } 
    } 
}