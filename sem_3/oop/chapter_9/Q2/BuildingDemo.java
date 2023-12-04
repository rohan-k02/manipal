import com.course.structure.*;
import static java.lang.System.out;

class BuildingDemo
{
    public static void main(String[] args)
    {
        Building b = new Building(2243.4, 4);
        House h = new House(2243.4, 4, 3, 3);
        out.println("Building sqft: " + b.sqFoot + "\nBeds in House: " + h.bed);
    }
}
