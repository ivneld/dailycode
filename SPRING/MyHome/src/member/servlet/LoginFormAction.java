package member.servlet;

import java.io.IOException;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class LoginFormAction extends HttpServlet {
  private static final long serialVersionUID = 1L;
  
  protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    String id = request.getParameter("id");
    boolean check = false;
    if (id != null) {
      Cookie[] cks = request.getCookies();
      if (cks != null) {
        byte b;
        int i;
        Cookie[] arrayOfCookie;
        for (i = (arrayOfCookie = cks).length, b = 0; b < i; ) {
          Cookie ck = arrayOfCookie[b];
          if (ck.getName().equals("ckid")) {
            id = ck.getValue();
            check = true;
            break;
          } 
          b++;
        } 
      } 
    } 
    request.setAttribute("id", id);
    request.setAttribute("check", Boolean.valueOf(check));
    RequestDispatcher rd = request.getRequestDispatcher("/login/form.jsp");
    rd.forward((ServletRequest)request, (ServletResponse)response);
  }
  
  protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    doGet(request, response);
  }
}
