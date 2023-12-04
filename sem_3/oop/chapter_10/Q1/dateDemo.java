/**
 * Define a class CurrentDate with data members day, month and year. Define a method
 * createDate() to create date object by reading values from keyboard. Throw a user
 * defined exception by name InvalidDayException if the day is invalid and
 * InvalidMonthException if month is found invalid and display cunent date if the date
 * is valid. Write a test program to illustrate the functionality.
*/

import java.util.Scanner;
import static java.lang.System.out;


class InvalidDayException extends Exception
{
    int day;

    InvalidDayException(int d)
    {
        super("Invalid Day");
        day = d;
    }

    public final String toString()
    {
        return "Invalid Day Entered. Acceptable Days are 1-32, but you have entered " + day;
    }
}

class CurrentDate
{
    int day, month, year;

    void createDate()
    {
        Scanner s = new Scanner(System.in);
        out.print("Enter day: ");
        day = s.nextInt();
        out.print("Enter month: ");
        month = s.nextInt();
        out.print("Enter year: ");
        year = s.nextInt();
    }
}


class dateDemo
{
    public static void main(String[] args) throws InvalidDayException
    {
        try
        {
            CurrentDate d1 = new CurrentDate();
            d1.createDate();

            if (d1.day > 31 || d1.day < 1) 
            {
                throw new InvalidDayException(d1.day);
            }
        }  
        
        catch(InvalidDayException e)
        {
            out.println(e);
        }
    }
}
