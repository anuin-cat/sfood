package com.socks.www.service.deal_message.merchant.delete;

import com.socks.www.dao.base.delete;
import com.socks.www.po.Emp_merchant;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/handle_merchant")
public class handle_merchant extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //归属
        System.out.println("-----handle_merchant-----");
/**
 * 删除操作的---------------------------------------------------------------------------------------------
 */
        //操作类型获取
        String operate = request.getParameter("operate");
        System.out.println(operate);
        //获取商品代号信息+商人信息
        String[] carts_num = request.getParameterValues("carts");
        Emp_merchant ys_merchant = (Emp_merchant) request.getSession().getAttribute("ys_merchant");


        if("delete".equals(operate)){
            //删除商品信息
            if(null==carts_num) {
                //删除商品操作
                //System.out.println("没有选择商品");
                request.setAttribute("state","no1");
                request.getRequestDispatcher("merchant.jsp").forward(request, response);
            }
            for (String cart_num : carts_num) {
                delete.deleteGoods(ys_merchant.getGoods_pool().toString(), cart_num);
            }
            request.getRequestDispatcher("merchant.jsp").forward(request, response);
        }else if("add".equals(operate)){
            //店铺添加商品操作
            request.getRequestDispatcher("/decision_goods_display").forward(request,response);
        }else if("change".equals(operate)){
            //店铺更改商品信息
            System.out.println("改变商品信息");
            //特殊情况
            String[] cart_num = request.getParameterValues("carts");
            if(null==cart_num||cart_num.length != 1){
                System.out.println("商品信息选择错误");
                request.setAttribute("state","no4");
                request.getRequestDispatcher("merchant.jsp").forward(request,response);
            }
            request.getSession().setAttribute("carts00",cart_num[0]);
            request.getRequestDispatcher("merchant_change_goods.jsp").forward(request,response);
        }

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
