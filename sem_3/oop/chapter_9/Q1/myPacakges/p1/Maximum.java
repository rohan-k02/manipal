package myPacakges.p1;

public class Maximum
{
    public static int max(int a, int b, int c)
    {
        int max = 0;
        
        if(a>b)
        {
            max = (a>c) ? a : c;        
        }

        else
        {
            max = (b>c) ? b : c;
        }

        return max;
    }
}
