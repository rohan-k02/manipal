class tester
{

    double add(int x, double y)
    {
        return x + y;
    }

    double add(double x, int y)
    {
        return x + y + 1;
    } 

}


public class test
{
    public static void main(String[] args)
    {
        tester t1 = new tester();
        t1.add(3, 3.14); 
        t1.add(3.14, 3);
        t1.add(3, 3); //ambiguous
        t1.add(3.14, 3.14); //no method found
    }
    
}
