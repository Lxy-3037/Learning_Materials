// Decompiled by Jad v1.5.8g. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://www.kpdus.com/jad.html
// Decompiler options: packimports(3) 
// Source File Name:   SimulationView.java

import java.util.Vector;

public class SimulationView
{

    public SimulationView()
    {
    }

    public static String getHtml(Simulation simulation)
    {
        HtmlPage htmlpage = new HtmlPage();
        htmlpage.setTitle("Fish Simulation");
        htmlpage.addText("<H2>Fish Simulation</H2>");
        HtmlTable htmltable = new HtmlTable(10);
        HtmlImage htmlimage1 = new HtmlImage("/blank.gif", "Maybe algae. No other life.");
        for(int i = simulation.getFirstRow(); i <= simulation.getLastRow(); i++)
        {
            htmltable.startRow();
            for(int j = simulation.getFirstColumn(); j <= simulation.getLastColumn(); j++)
            {
                String s = "aqua";
                HtmlImage htmlimage = htmlimage1;
                Vector vector = simulation.getNeighbors(i, j, 0);
                for(int k = 0; k < vector.size(); k++)
                {
                    LivingBeing livingbeing = (LivingBeing)vector.get(k);
                    htmlimage = new HtmlImage(livingbeing.getImage(), "Catfish");
                }

                htmltable.addCell(s, htmlimage.buildHtml());
            }

            htmltable.endRow();
        }

        htmlpage.addText(htmltable.buildHtml());
        return htmlpage.buildHtml();
    }
}
