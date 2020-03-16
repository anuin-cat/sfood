package com.socks.www.service.deal_message.user.delete;

import com.socks.www.dao.base.add;
import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_decision_pool_goods;
import com.socks.www.po.Emp_merchant;
import com.socks.www.po.Emp_user;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/remove_cart")
public class remove_cart extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        System.out.println("-----remove_cart-----");
        //获取用户信息
        Emp_user ys_user = (Emp_user) request.getSession().getAttribute("ys_user");

        System.out.println(ys_user);

        //获取商品信息
        String[] cart_nums = request.getParameterValues("carts");

        //判断特殊情况
        if(null==cart_nums){
            //未选择商品数据
            request.setAttribute("state","no0");
            request.getRequestDispatcher("user.jsp").forward(request,response);
        }

        System.out.println(cart_nums[0]);

        //循环删除商品信息
        for(String cart_num:cart_nums){
            dateBase.DML("delete from cart_pl where cart_num="+cart_num+" and "+"cart_pool="+ys_user.getCart_pool());
        }

        //设置状态信息
        request.setAttribute("state","yes0");
        request.getRequestDispatcher("object_display").forward(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
