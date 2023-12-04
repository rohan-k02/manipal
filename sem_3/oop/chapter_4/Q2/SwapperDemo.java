class Swapper
{
    int x, y;

    Swapper(int x1, int y1)
    {
        this.x = x1;
        this.y = y1;
    }

    public int getX()
    {
        return x;
    }

    public int getY()
    {
        return y;
    }

    void swap()
    {
        int temp;
        temp = x;
        x = y;
        y = temp;
    }
}


class SwapperDemo
{
    public static void main(String[] args)
    {
        Swapper s1 = new Swapper(1, 2);
        System.out.println("The value of x is: " + s1.getX() + "\nThe value of y is: " + s1.getY());

        s1.swap();
        System.out.println("\nSwapping...\nThe value of x is: " + s1.getX() + "\nThe value of y is: " + s1.getY());
    }
    
}
