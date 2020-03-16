package com.socks.www.service.deal_message.user.base;

import com.socks.www.dao.base.add;
import com.socks.www.po.Emp_user;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/become_merchant")
public class become_merchant extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //标识
        System.out.println("-----become_merchant-----");

        //获取用户信息
        Emp_user ys_user = (Emp_user) request.getSession().getAttribute("ys_user");

        //添加决策池用户信息
        add.addDecisionUser(ys_user);

        //设置状态并转发
        request.setAttribute("state","yes5");
        request.getRequestDispatcher("user.jsp").forward(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
