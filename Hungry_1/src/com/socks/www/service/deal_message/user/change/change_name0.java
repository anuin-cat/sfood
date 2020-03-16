package com.socks.www.service.deal_message.user.change;

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

@WebServlet("/change_name0")
public class change_name0 extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //获取商家信息
        Emp_user ys_user = (Emp_user) request.getSession().getAttribute("ys_user");

        //获取表单新昵称
        String name = request.getParameter("name");

        //修改商家昵称
        dateBase.DML("update user set name='"+name+"' where account='"+ys_user.getAccount()+"'");

        //重新存储商家信息
        List<Emp_user> user = dateBase.userToQuery(
                "select * from user where account=" + ys_user.getAccount()
        );
        request.getSession().setAttribute("ys_user",user.get(0));

        //保存并转发
        request.setAttribute("state","yes4");
        request.getRequestDispatcher("user_change_name.jsp").forward(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
