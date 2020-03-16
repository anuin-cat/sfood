package com.socks.www.service.deal_message.user.base;

import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_merchant;
import com.socks.www.po.Emp_user;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/recharge0")
public class recharge0 extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //标志
        System.out.println("-----recharge0-----");

        //获取表单信息
        String count = request.getParameter("count");
        String code = request.getParameter("code");

        //获取用户信息
        Emp_user ys_user = (Emp_user) request.getSession().getAttribute("ys_user");

        //查询验证码
        Integer code_num = (Integer) dateBase.queryForObject("select count(code) from code where code='"+code+"'", Integer.class);

        if(0 == code_num){
            System.out.println("验证码错误");
            request.setAttribute("state","no5");
            request.getRequestDispatcher("user_recharge.jsp").forward(request,response);
        }else{
            dateBase.DML("update user set balance=balance+"+count+" where account='"+ys_user.getAccount()+"'");
            request.getRequestDispatcher("refresh_account0").forward(request,response);
        }

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
















