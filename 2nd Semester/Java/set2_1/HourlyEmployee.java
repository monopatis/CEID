public class HourlyEmployee extends Employee
{
    private int hoursWorked = 0;
    private int hourlyPayment = 0;
    
    public HourlyEmployee ()
    {
    }
    
    public void setHoursWorked(int hw) {hoursWorked = hw;}
    public int getHoursWorked() {return hoursWorked;}
    public void setHourlyPayment(int hp) {hourlyPayment = hp;}
    public int getHourlyPayment() {return hourlyPayment;}
    public int payment() {return hoursWorked * hourlyPayment;}
}

