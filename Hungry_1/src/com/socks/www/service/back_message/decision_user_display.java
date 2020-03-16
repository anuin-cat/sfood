package com.socks.www.service.back_message;

import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_decision_pool_user;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/decision_user_display")
public class decision_user_display extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //标识
        System.out.println("-----decision_user_display-----");

        //获取用户转商家的信息
        List<Emp_decision_pool_user> decision_users = dateBase.decision_pool_userToQuery(
                "select * from decision_pl_user");

        System.out.println(decision_users);

        //存储信息
        request.getSession().setAttribute("decision_users",decision_users);
        request.getRequestDispatcher("/root.jsp").forward(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
