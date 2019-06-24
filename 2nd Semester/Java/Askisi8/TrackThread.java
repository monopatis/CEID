public class TrackThread extends Thread { 
    int m; 
     
    public TrackThread(String str, int m) { 
        super(str); 
        this.m = m; 
    } 
    public void run() { 
        System.out.println(getName() + " started running!"); 
        for (int i = 0; i < m; i+=20) { 
            System.out.println(getName() + " has just passed the " + i + " meters."); 
            try { 
                sleep((long)(Math.random() * 1000)); 
            } catch (InterruptedException e) {} 
        } 
        System.out.println(getName() + " has finished the " + m + "m. race."); 
    } 
}