package com.socks.www.service.deal_message.connect;

import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_merchant;
import com.socks.www.po.Emp_user;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/refresh_account0")
public class refresh_account0 extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //获取账户信息
        Emp_user ys_user = (Emp_user) request.getSession().getAttribute("ys_user");

        //重新获取账户信息
        List<Emp_user> user = dateBase.userToQuery("select * from user where account=" + ys_user.getAccount());

        //重新存储商家信息
        request.getSession().setAttribute("ys_user",user.get(0));
        request.setAttribute("state","yes3");
        request.getRequestDispatcher("user_recharge.jsp").forward(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
