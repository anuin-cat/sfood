package com.socks.www.service.back_message;

import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_object_pool;
import com.socks.www.po.Emp_user;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

/**
 * 用来在用户页面刷新点击商家之后的商品展示
 */
@WebServlet("/goods_display")
public class goods_display extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //标志
        System.out.println("-----goods_display------");

        //表单获取商家信息
        String goods_pool = request.getParameter("merchant_choice");

        //创建session对象
        HttpSession session = request.getSession();

        //查询返回所有商品,查询购物车
        List<Emp_object_pool> goods = dateBase.object_poolToQuery
                ("select distinct object_pl.id,object_pl.cart_num,name,price,described " +
                        "from goods_pl left join object_pl on goods_pool="+goods_pool+
                        " and goods_pl.`cart_num`=object_pl.`cart_num`");

        //储存商品数据
        session.setAttribute("object_pool",goods);
        request.getRequestDispatcher("/user.jsp").forward(request,response);


    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
