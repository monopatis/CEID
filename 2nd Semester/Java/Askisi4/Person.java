public class Person { 
private String lastname; 
private String firstname; 
private int age; 
private boolean married; 
private float salary; 
public static final int MALE = 0; 
public static final int FEMALE = 1; 
private int sex; 
 
public Person (String lastname, String firstname, int age, boolean married, 
float salary, int sex) { 
  this.lastname = new String(lastname);
  this.firstname = new String(firstname); 
  this.age = age; 
  this.married = married; 
  this.salary = salary; 
  this.sex = sex; 
} 
 
public String getLastName() { return lastname; } 
public String getFirstName() { return firstname; } 
public int getAge() { return age; } 
public boolean isMarried() { return married; } 
public float getSalary() { return salary; } 
public void printInfo()
    {
        System.out.print(getFirstName()+" "+getLastName()+" is "
        +getAge()+" years old ");
        if (sex == MALE) System.out.print("male");
        else System.out.print("female");
        System.out.print(", gets a "+getSalary()
        +" Euros salary and is");
        if (isMarried() == false)
        System.out.print(" not");
        System.out.println(" married.");
    }
public void setLastName(String lastname) {this.lastname = lastname;}
public void setFirstName(String firstname) {this.firstname = firstname;}
public void setAge(int age) {this.age = age;}
public void setMarried(boolean married) {this.married = married;}
public void setSalary(float salary) {this.salary = salary;}
public int getSex() { return sex; }
public void setSex(int Sex) {this.sex = Sex;}
} 