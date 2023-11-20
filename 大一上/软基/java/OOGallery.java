import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class OOGallery extends HttpServlet {
	public void doPost(HttpServletRequest request,
						HttpServletResponse response)
						throws ServletException, IOException {

		/**
		 *  Indicate the content type (for example, text/html), 
		 *  being returned by the response
		 */
		response.setContentType("text/html");

		/** 
		 * 	Retrieve an output stream to use to send data to the client 
		 */
		PrintWriter out = response.getWriter();

		/**
		 *	 Get the user input from the form
		 */
		String bgrnd = request.getParameter("bgrnd");
		String theme = request.getParameter("theme");

		/** 
		 * 	Create an instance of the HtmlPage class 
		 */
		HtmlPage mypage=new HtmlPage();
		mypage.setTitle("OOGallery");
		/**
         *  Set the title for the response Web page
         */
		HtmlImage Imageone=new HtmlImage("/servlet/"+theme+"One.jpg",theme+"One");

		/** 
		 * 	Create an instance of the HtmlImage class for the first image
		 */
                                HtmlImage Imagetwo=new HtmlImage("/servlet/"+theme+"Two.jpg",theme+"Two");

		/** 
		 * 	Create an instance of the HtmlImage class for the second image
		 */
		mypage.setBackgroundImage("/servlet/"+bgrnd+".gif");

		/** 
		 * 	Set the attributes of the HtmlPage object 
		 */
		mypage.addText(Imageone.buildHtml());
		mypage.addText(Imagetwo.buildHtml());
		/** 
		 * 	Add the images 
		 */
		out.println(mypage.buildHtml());

		/**
		 *	 Construct the HTML response
		 */
		
	}
}
