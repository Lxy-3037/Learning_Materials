// Decompiled by Jad v1.5.8g. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://www.kpdus.com/jad.html
// Decompiler options: packimports(3) 
// Source File Name:   LivingBeing.java


public abstract class LivingBeing
{

    public LivingBeing()
    {
    }

    public static void createLivingBeing(Simulation simulation, String s, String s1)
    {
        int i = Integer.parseInt(s1);
        int j = i / 100;
        int k = i - 100 * j;
        if(s.equals("catfish"))
            simulation.addLivingBeing(new Catfish(j, k, simulation));
    }

    public abstract int getRow();

    public abstract int getColumn();

    public abstract int getAge();

    public abstract String getImage();

    public abstract int getEnergy();

    public abstract boolean isDead();

    public abstract void liveALittle();
}
