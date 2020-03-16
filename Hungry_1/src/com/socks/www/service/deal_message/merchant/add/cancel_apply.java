package com.socks.www.service.deal_message.merchant.add;

import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_merchant;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/cancel_apply")
public class cancel_apply extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        System.out.println("-----cancel_apply-----");
        //获取商家信息
        Emp_merchant ys_merchant = (Emp_merchant) request.getSession().getAttribute("ys_merchant");

        System.out.println(ys_merchant);

        //获取商品信息
        String[] cart_nums = request.getParameterValues("carts");

        //判断特殊情况
        if(null==cart_nums){
            //未选择商品数据
            request.setAttribute("state","no0");
            request.getRequestDispatcher("merchant_add_goods.jsp").forward(request,response);
        }

        System.out.println(cart_nums[0]);

        //循环删除商品信息
        for(String cart_num:cart_nums){
            dateBase.DML("delete from decision_pl_goods where cart_num="+cart_num+" and "+"goods_pool="+ys_merchant.getGoods_pool());
        }

        //设置状态信息
        request.setAttribute("state","no");
        request.getRequestDispatcher("merchant_add_goods.jsp").forward(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}










