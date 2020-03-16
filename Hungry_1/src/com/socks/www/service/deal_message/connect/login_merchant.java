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

@WebServlet("/login_merchant")
public class login_merchant extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        //得到账号密码+存储商家账户信息
        Emp_merchant merchant = new Emp_merchant();
        merchant.setAccount(request.getParameter("account"));
        merchant.setPassword(request.getParameter("password"));


        //查询账号数据
        List<Emp_merchant> merchants = dateBase.merchantToQuery(
                "select * from merchant where account='" + merchant.getAccount() + "' and password='" + merchant.getPassword() + "'"
        );

        String state;

        //判断是否有此人数据
        if(merchants.size()==0){
            state = "2";    //没有
        }else{
            state = "3";    //有
            //存储商家信息
            request.getSession().setAttribute("ys_merchant",merchants.get(0));
            //System.out.println("-----login_merchant-----");
            //System.out.println(merchants.get(0));
        }


        //储存判断信息
        request.setAttribute("state",state);
        request.getRequestDispatcher("main.jsp").forward(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
