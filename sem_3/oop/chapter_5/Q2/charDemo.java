/** Implement a charArray2string( ) method that takes a char array as its parameter.
It creates and returns a String that contains the same characters in the
same order as in the array. */

class charMan
{
    String str;
    char[] arr;

    charMan(char[] arr1)
    {
        arr = arr1.clone();
        str = "";
    }

    void charArray2string()
    {
        for(int i = 0; i < arr.length; i++)
        {
            str += arr[i];
        }
    }

    void display()
    {
        System.out.println(str);
    }
}

/**
 * stringDemo
 */
public class charDemo
{
    public static void main(String[] args)
    {
        char arr[] = {'T', 'e', 's', 't', ' ', 'i', 't', '.'};
        charMan sman = new charMan(arr);
        sman.charArray2string();

        sman.display();
    }
}