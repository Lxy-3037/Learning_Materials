// Decompiled by Jad v1.5.8g. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://www.kpdus.com/jad.html
// Decompiler options: packimports(3) 
// Source File Name:   SimulationServlet.java

import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;
import javax.servlet.ServletException;
import javax.servlet.http.*;

public class SimulationServlet extends HttpServlet
{

    public SimulationServlet()
    {
    }

    public void doGet(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException
    {
        doPost(request, response);
    }

    public void doPost(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException
    {
        int totalTimeBlocksToSimulate = 0;
        HttpSession session = request.getSession();
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        String numTimeBlocks = request.getParameter("numTimeBlocks");
        Simulation sim;
        if(numTimeBlocks != null)
        {
            totalTimeBlocksToSimulate = Integer.parseInt(numTimeBlocks);
            sim = new Simulation(0, 0, 9, 9);
            Map allParams = request.getParameterMap();
            Set allKeys = allParams.keySet();
            for(Iterator it = allKeys.iterator(); it.hasNext();)
            {
                String key = (String)it.next();
                if(!key.equals("Submit") && !key.equals("numTimeBlocks"))
                {
                    String value[] = (String[])allParams.get(key);
                    for(int i = 0; i < value.length; i++)
                        LivingBeing.createLivingBeing(sim, key, value[i]);

                }
            }

            if(totalTimeBlocksToSimulate > 0)
                response.setHeader("Refresh", "1");
            out.print(SimulationView.getHtml(sim));
            session.setAttribute("simulation", sim);
            session.setAttribute("totalTimeBlocksToSimulate", numTimeBlocks);
            return;
        }
        sim = (Simulation)session.getAttribute("simulation");
        String totalTimeBlocksInSession = (String)session.getAttribute("totalTimeBlocksToSimulate");
        if(totalTimeBlocksInSession != null)
            totalTimeBlocksToSimulate = Integer.parseInt(totalTimeBlocksInSession);
        if(sim.getTime() < totalTimeBlocksToSimulate - 1)
            response.setHeader("Refresh", "1");
        sim.simulateATimeBlock();
        out.print(SimulationView.getHtml(sim));
    }

    private static final int DEBUG = 10;
}
