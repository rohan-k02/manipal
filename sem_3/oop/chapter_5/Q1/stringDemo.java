/** Implement a string2charArray( ) method that takes a String as its parameter.
It creates and returns a char array containing the same characters in the same
order as in the string. */

class Stringman
{
    String str;
    char[] arr;

    Stringman(String s)
    {
        str = s;
        arr = new char[s.length()];
    }

    void string2charArray()
    {
        for(int i = 0; i < str.length(); i++)
        {
            arr[i] = str.charAt(i);
        }
    }

    void display()
    {
        for(int i = 0; i < arr.length; i++)
        {
            System.out.print(arr[i]);
        }
    }
}

/**
 * stringDemo
 */
public class stringDemo
{
    public static void main(String[] args)
    {
        Stringman sman = new Stringman("Test this out");
        sman.string2charArray();

        sman.display();
    }
}