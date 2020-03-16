package com.socks.www.service.deal_message.user.add;

import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_cart_pool;
import com.socks.www.po.Emp_user;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/add_cart")
public class add_cart extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //获取用户信息
        Emp_user ys_user = (Emp_user) request.getSession().getAttribute("ys_user");
        //获取商品信息
        String[] carts = request.getParameterValues("carts");

        //查询是否商品重复
        for (String cart:carts) {
            //遍历所有选中商品
            List<Emp_cart_pool> cart_pools = dateBase.cart_poolToQuery(
                    "select * from  cart_pl where cart_num="+cart+" and cart_pool="+ys_user.getCart_pool()
            );
            if (cart_pools.size()!=0) {
                System.out.println("-----add_cart-----");
                System.out.println("商品重复");
                System.out.println("商品代号："+cart);
                System.out.println(
                        dateBase.queryForObject("select count(cart_num) from cart_pl where cart_num="+cart, String.class)
                );
                request.setAttribute("state", "cart_repeat");
                request.getRequestDispatcher("/user.jsp").forward(request, response);
            }
        }

        //将商品加入用户购物车
        for(String cart:carts){
            //商品代号+购物车代号
            dateBase.DML("insert into cart_pl values ("+cart+","+ys_user.getCart_pool()+")");
        }

        //反馈信息
        request.setAttribute("state","add_yes");

        //返回用户个人页面
        request.getRequestDispatcher("/object_display").forward(request,response);

        System.out.println(carts[1]+"  "+carts[0]+"    "+ys_user.getCart_pool());

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
