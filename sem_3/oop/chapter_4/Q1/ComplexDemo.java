/**
* Class that defines a complex number
*/
class Complex
{
    int a, b;

    Complex(int a1, int b1)
    {
        a = a1;
        b = b1;
    }

    /**
    * Displays a complex number in a+ib format
    */
    void display()
    {
        System.out.println(a + " + " + b + "i\n");
    }

    /**
    * Adds two complex numbers: the object that calls the function and the object specified in the argument.
    */
    Complex add(Complex c2)
    {
        Complex c3 = new Complex((this.a + c2.a), (this.b + c2.b));
        return c3;
    }
}


/**
 * Driver class for the program
 */
class ComplexDemo
{
    public static void main(String[] args)
    {
        Complex c1 = new Complex(5, 3);
        Complex c2 = new Complex(15, 4);

        System.out.print("First complex number: ");
        c1.display();
        System.out.print("Second complex number: ");
        c2.display();

        Complex c3 = c1.add(c2);
        System.out.print("Sum of both complex numbers: ");

        c3.display();
        
    }
    
}