public class Main
{
    public static void main(String args[])
    {
        Employee e[] = new Employee[2];
        e[0] = new SalariedEmployee();
        e[1] = new HourlyEmployee();
        e[0].setName("Gewrgiou");
        e[0].setAfm("7777777");
        ((SalariedEmployee)e[0]).setSalary(300000);
        e[1].setName("Karamitros");
        e[1].setAfm("8888888");
        ((HourlyEmployee)e[1]).setHoursWorked(3000);
        ((HourlyEmployee)e[1]).setHourlyPayment(40);
        
        for (int i=0; i<2; i++) {
            System.out.println ("Employee ID:" + e[i].getEmpID());
            System.out.println ("Employee name:" + e[i].getName());
            System.out.println ("Employee AFM:" + e[i].getAfm());
            System.out.println ("Employee salary:" + e[i].payment());
            System.out.println(" ");
       }
    }
}