public abstract class Employee 
{
    private long EmpID;
    private static long aa;
    private String name = "";
    private String afm = "";
    
    public Employee()
    {
        aa = aa + 1;
        this.EmpID = aa;
    }
        
    public void setName(String name) {this.name = name;}
    public String getName() {return name;}
    public void setAfm(String a) {this.afm = a;}
    public String getAfm() {return afm;}
    public long getEmpID() {return EmpID;}
    abstract int payment();
}
