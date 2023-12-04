package com.course.structure;

public class House extends Building
{
    public int bed;
    public int bath;

    public House(double sf, int st, int be, int ba)
    {
        super(sf, st);
        bed = be;
        bath = ba;
    }    
}
