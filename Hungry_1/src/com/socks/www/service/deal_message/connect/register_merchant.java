package com.socks.www.service.deal_message.connect;

import com.socks.www.dao.base.add;
import com.socks.www.dao.check;
import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_user;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

@WebServlet("/register_merchant")
public class register_merchant extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        //获取两个密码
        String a1 = request.getParameter("password1");
        String a2 = request.getParameter("password2");

        String b1 = request.getParameter("random");
        String b2 = (String) request.getSession().getAttribute("random");
        request.getSession().removeAttribute("random");
//        System.out.println(b1+"    "+b1.length());
//        System.out.println(b2+"    "+b2.length());

        //设定字符集
        request.setCharacterEncoding("UTF-8");
        if(!b1.equals(b2)) {
            //验证码输入错误
            request.setAttribute("state","no0");
            System.out.println("验证码错误");
            request.getRequestDispatcher("/register.jsp").forward(request,response);
        }else if(check.checkAccount(request.getParameter("account"))){
            //账号已存在
            request.setAttribute("state","no1");
            System.out.println("账户已存在");
            request.getRequestDispatcher("/register.jsp").forward(request,response);

        } else if(!a1.equals(a2)){
            //两次密码输入不一致
            request.setAttribute("state","no2");
            System.out.println("密码输入不一致");
            request.getRequestDispatcher("/register.jsp").forward(request,response);
        }else {
            //条件满足，生成用户
            System.out.println("条件全部符合");
            Emp_user user = new Emp_user();
            user.setName((String) request.getParameter("userName"));
            user.setPassword((String) request.getParameter("password1"));
            user.setAccount((String) request.getParameter("account"));
            //创建用户
            add.addUser(user);
            System.out.println("创建用户中");
            //查询并储存用户信息
            List<Emp_user> account = dateBase.userToQuery("select * from user where account = '" + request.getParameter("account"));
            if(account.size()!=0){
                HttpSession session = request.getSession();
                session.setAttribute("ys_user",account.get(0));
                request.setAttribute("state","yes0");
                request.getRequestDispatcher("/login").forward(request,response);
            }else{
                request.setAttribute("state","no3");
                request.getRequestDispatcher("/register.jsp").forward(request,response);
                PrintWriter out=response.getWriter();
                out.println("<html>");//输出的内容要放在body中
                out.println("<body>");
                out.println("用户创建失败，请重试");
                out.println("</body>");
                out.println("</html>");
            }
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
