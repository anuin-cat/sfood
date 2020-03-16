package com.socks.www.service.deal_message.merchant.change;

import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_merchant;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/change_name")
public class change_name extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //获取商家信息
        Emp_merchant ys_merchant = (Emp_merchant) request.getSession().getAttribute("ys_merchant");

        //获取表单新昵称
        String name = request.getParameter("name");

        //修改商家昵称
        dateBase.DML("update merchant set name='"+name+"' where account='"+ys_merchant.getAccount()+"'");

        //重新存储商家信息
        List<Emp_merchant> merchant = dateBase.merchantToQuery(
                "select * from merchant where account=" + ys_merchant.getAccount()
        );
        request.getSession().setAttribute("ys_merchant",merchant.get(0));

        //保存并转发
        request.setAttribute("state","yes4");
        request.getRequestDispatcher("merchant_change_name.jsp").forward(request,response);

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
