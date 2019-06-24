 public class Runners { 
    public static void main (String[] args) { 
        System.out.println("Men 400m Hurdles Track with 3 runners!"); 
        new TrackThread("Llewellyn Herbert", 400).start(); 
        new TrackThread("Stephane Diagana", 400).start(); 
        new TrackThread("Samuel Matete", 400).start();
    } 
}