/**
 * Create a Person class with private instance variables for the person’s name
 * and birth date. Add appropriate accessor methods for these variables. Then
 * create a subclass CollegeGraduate with private instance variables for the
 * student’s GPA and year of graduation and appropriate accessors for these
 * variables. Don’t forget to include appropriate constructors for your classes.
 * Then create a class with a main( ) method that demonstrates your classes.
 */


 class Person
 {
    private String name;
    private int dob;

    Person(String n, int d)
    {
        name = n;
        dob = d;
    }

    String getName()
    {
        return name;
    }

    int getDob()
    {
        return dob;
    }
 }

 class CollegeGraduate extends Person
 {
    private double GPA;

    CollegeGraduate(String n, int d, double g)
    {
        super(n, d);
        GPA = g;
    }

    double getGPA()
    {
        return GPA;
    }
}


public class collegeDemo
{
    public static void main(String[] args)
    {
        CollegeGraduate c = new CollegeGraduate("Rohan", 240702, 9.6);

        System.out.println("Details\nName: " + c.getName() + "\nDate of Birth: " + c.getDob() + "\nGPA: " + c.getGPA());
    }
}
