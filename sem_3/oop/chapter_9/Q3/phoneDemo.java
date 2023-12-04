/** 
 * Create a class Phone{st:ring brand, int memCapacity}, which contains an interface
 * (Nested interface) Callable{makeAudioCall(string cellNum), makeVideoCall(string
 * cellNum)}. Create subclasses BasicPhone and Smai1Phone and implement the
 * methods appropriately. Demonstrate the creation of both subclass objects by calling
 * approp1iate conshuctors which accepts values fo1m the user. Using these objects call
 * the methods of the interface.
*/

import static java.lang.System.out;

class Phone
{
    String brand;
    int memCapacity;

    Phone(String b, int m)
    {
        brand = b;
        memCapacity = m;
    }

    interface Callable
    {
        void makeAudioCall(String cellNum);
        void makeVideoCall(String cellNum);          
    }
}

class BasicPhone extends Phone implements Phone.Callable
{
    BasicPhone(String b, int m)
    {
        super(b, m);
    }

    public void makeAudioCall(String cellNum)
    {
        out.println("Calling " + cellNum);
    }

    public void makeVideoCall(String cellNum)
    {
        out.println("Calling" + cellNum);
    }
}

class phoneDemo
{
    public static void main(String[] args)
    {
        BasicPhone b = new BasicPhone("Nokia", 4);

        b.makeAudioCall("999932043");
        b.makeVideoCall("928483432");
    }
}