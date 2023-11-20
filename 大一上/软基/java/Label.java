// Decompiled by Jad v1.5.8g. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://www.kpdus.com/jad.html
// Decompiler options: packimports(3) 
// Source File Name:   Label.java

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.*;

public class Label extends HttpServlet
{

    public Label()
    {
    }

    public void doPost(HttpServletRequest httpservletrequest, HttpServletResponse httpservletresponse)
        throws ServletException, IOException
    {
        httpservletresponse.setContentType("text/html");
        PrintWriter printwriter = httpservletresponse.getWriter();
        String s = httpservletrequest.getParameter("SenderName");
        String s1 = httpservletrequest.getParameter("SenderStrtAddr");
        String s2 = httpservletrequest.getParameter("SenderCityZip");
        String s3 = httpservletrequest.getParameter("ReceiverName");
        String s4 = httpservletrequest.getParameter("ReceiverStrtAddr");
        String s5 = httpservletrequest.getParameter("ReceiverCityZip");
        String s6 = httpservletrequest.getParameter("destination");
        printwriter.println("<!DOCTYPE HTML PUBLIC '-//W3C//DTD HTML 4.01 Transitional//EN'>");
        printwriter.println("<HTML>");
        printwriter.println("<HEAD><TITLE>ShippingLabelForm</TITLE></HEAD>");
        printwriter.println("<BODY bgcolor='#fdf5e6'>");
        printwriter.println("<TABLE>");
        String s7 = (new StringBuilder()).append("<IMG src='/myapp").append(s6).append("'>").toString();
        printwriter.println("<TR>");
        printwriter.println("<TD>");
        printwriter.println("<B>From:-</B>");
        printwriter.println("</TD>");
        printwriter.println("<TD>");
        printwriter.println("</TD>");
        printwriter.println("<TD>");
        printwriter.println("</TD>");
        printwriter.println("<TD>");
        printwriter.println("</TD>");
        printwriter.println("</TR>");
        printwriter.println("<TR>");
        printwriter.println("<TD>");
        printwriter.println((new StringBuilder()).append("<P>").append(s).append("</P>").toString());
        printwriter.println((new StringBuilder()).append("<P>").append(s1).append("</P>").toString());
        printwriter.println((new StringBuilder()).append("<P>").append(s2).append("</P>").toString());
        printwriter.println("</TD>");
        printwriter.println("<TD>");
        printwriter.println("</TD>");
        printwriter.println("<TD>");
        printwriter.println("</TD>");
        printwriter.println("<TD align='right' valign='top'>");
        printwriter.println(s7);
        printwriter.println("</TD>");
        printwriter.println("</TR>");
        printwriter.println("<TR>");
        printwriter.println("<TD>");
        printwriter.println("</TD>");
        printwriter.println("<TD>");
        printwriter.println("<BR><BR><B>To:-</B>");
        printwriter.println("</TD>");
        printwriter.println("<TD>");
        printwriter.println("</TD>");
        printwriter.println("<TD>");
        printwriter.println("</TD>");
        printwriter.println("</TR>");
        printwriter.println("<TR>");
        printwriter.println("<TD>");
        printwriter.println("</TD>");
        printwriter.println("<TD>");
        printwriter.println("</TD>");
        printwriter.println("<TD>");
        printwriter.println((new StringBuilder()).append("<P>").append(s3).append("</P>").toString());
        printwriter.println((new StringBuilder()).append("<P>").append(s4).append("</P>").toString());
        printwriter.println((new StringBuilder()).append("<P>").append(s5).append("</P>").toString());
        printwriter.println("</TD>");
        printwriter.println("<TD>");
        printwriter.println("</TD>");
        printwriter.println("</TR>");
        printwriter.println("</TABLE>");
        printwriter.println("</BODY>");
        printwriter.println("</HTML>");
    }
}
