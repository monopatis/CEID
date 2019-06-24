public class LockerStory { 
    public static void main(String[] args) { 
        Locker l = new Locker(); 
        Storer s = new Storer(l, 1); 
        Remover r = new Remover(l, 1); 
 
        s.start(); 
        r.start(); 
    } 
}