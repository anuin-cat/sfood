package com.socks.www.service.deal_message.merchant.change;

import com.socks.www.dao.dateBase;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/change_goods")
public class change_goods extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //标识
        System.out.println("-----change_goods-----");

        //获取商品表单信息
        String name = request.getParameter("name");
        String price = request.getParameter("price");
        String described = request.getParameter("described");

        //改变商品池中的商品信息
        dateBase.DML("update object_pl set name='"+name+"',price="+price+",described='"+described+"'");
        request.setAttribute("state","yes2");
        request.getRequestDispatcher("merchant.jsp").forward(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
