package com.socks.www.service.deal_message.connect;

import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_merchant;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/refresh_account")
public class refresh_account extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //获取账户信息
        Emp_merchant ys_merchant = (Emp_merchant) request.getSession().getAttribute("ys_merchant");

        //重新获取账户信息
        List<Emp_merchant> merchant = dateBase.merchantToQuery("select * from merchant where account=" + ys_merchant.getAccount());

        //重新存储商家信息
        request.getSession().setAttribute("ys_merchant",merchant.get(0));
        request.setAttribute("state","yes3");
        request.getRequestDispatcher("merchant_recharge.jsp").forward(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
