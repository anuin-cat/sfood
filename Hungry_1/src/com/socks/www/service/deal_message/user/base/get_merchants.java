package com.socks.www.service.deal_message.user.base;

import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_merchant;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/get_merchants")
public class get_merchants extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //标识
        System.out.println("-----get_merchants-----");

        //获取所有商家信息，并Session存储
        List<Emp_merchant> merchants = dateBase.merchantToQuery("select * from merchant");
        request.getSession().setAttribute("merchants",merchants);

        System.out.println(merchants.get(0));

        //设置状态，进行转发
        request.setAttribute("merchants","1");
        request.getRequestDispatcher("user.jsp").forward(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
