package com.socks.www.service.deal_message.merchant.base;

import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_merchant;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/recharge")
public class recharge extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //标志
        System.out.println("-----recharge-----");

        //获取表单信息
        String count = request.getParameter("count");
        String code = request.getParameter("code");

        //获取商家信息
        Emp_merchant ys_merchant = (Emp_merchant) request.getSession().getAttribute("ys_merchant");

        //查询验证码
        Integer code_num = (Integer) dateBase.queryForObject("select count(code) from code where code='"+code+"'", Integer.class);

        if(0 == code_num){
            System.out.println("验证码错误");
            request.setAttribute("state","no5");
            request.getRequestDispatcher("merchant_recharge.jsp").forward(request,response);
        }else{
            dateBase.DML("update merchant set balance=balance+"+count+" where account='"+ys_merchant.getAccount()+"'");
            request.getRequestDispatcher("refresh_account").forward(request,response);
        }

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
















