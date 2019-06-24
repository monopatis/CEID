public class SalariedEmployee extends Employee
{
    private int salary = 0;
    
   
 public SalariedEmployee()
    {
    }
    
    public void setSalary(int s) {salary = s;}
    public int payment() {return salary;}
}

