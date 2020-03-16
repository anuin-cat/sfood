package com.socks.www.service.back_message;

import com.mysql.cj.Session;
import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_cart_pool;
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

@WebServlet("/object_display")
public class object_display extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //创建session对象
        HttpSession session = request.getSession();
        //查询返回所有商品,查询购物车
        Emp_user ys_user = (Emp_user) session.getAttribute("ys_user");
        List<Emp_object_pool> cart_pool = dateBase.object_poolToQuery
                ("select distinct object_pl.id,object_pl.cart_num,name,price,described " +
                        "from cart_pl left join object_pl on cart_pool="+ys_user.getCart_pool()+
                        " and cart_pl.`cart_num`=object_pl.`cart_num`");


        List<Emp_object_pool> object_pool = dateBase.object_poolToQuery("select * from object_pl");

        //储存商品数据
        session.setAttribute("cart_pool",cart_pool);
        session.setAttribute("object_pool",object_pool);
        request.setAttribute("state","just_0");
        request.getRequestDispatcher("/get_merchants").forward(request,response);

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
