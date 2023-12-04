/**
 * Create a class named ‘Staff' having the following members: Data members
 * 1 - Name
 * 2 - Age
 * 3 - Phone number
 * 4 - Address
 * 5 - Salary
 * 
 * It also has a method named 'printSalary' which prints the salary of the members.
 * 
 * Two classes 'Employee' and 'Manager' inherits the ‘Staff' class. 
 * The 'Employee' and 'Manager' classes have data members ‘role' and 'domain' respectively.
 * Now, assign name, age, phone number, address and salary to an employee and a manager by making an object of both of these classes and print the same. 
 * Make use of parameterized constructors in all the classes.
*/




class Staff
{
    String name;
    int age;
    int phone;
    String address;
    int salary;

    Staff(String n, int a, int p, String addr, int s)
    {
        name = n;
        age = a;
        phone = p;
        address = addr;
        salary = s;
    }

    void printSalary()
    {
        System.out.println("Salary: " + salary);
    }   
}


class Employee extends Staff
{
    String role;

    Employee(String n, int a, int p, String addr, int s, String r)
    {
        super(n, a, p, addr, s);
        role = r;
    }

}

class Manager extends Staff
{
    String domain;

    Manager(String n, int a, int p, String addr, int s, String d)
    {
        super(n, a, p, addr, s);
        domain = d;
    }
}

class demo
{
    public static void main(String[] args)
    {
        Employee e1 = new Employee("Rajesh", 32, 99771123, "Mumbai", 50000, "SDE");
        Manager m1 = new Manager("Mahesh", 40, 988748737, "Mumbai", 100000, "Development");

        e1.printSalary();
        m1.printSalary();             
    }
}