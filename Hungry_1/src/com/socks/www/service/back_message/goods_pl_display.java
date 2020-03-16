package com.socks.www.service.back_message;

import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_goods_pool;
import com.socks.www.po.Emp_merchant;
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

@WebServlet("/goods_pl_display")
public class goods_pl_display extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //标识
        //System.out.println("-----goods_pl_display-----");

        //创建session对象+接收商家账号信息
        HttpSession session = request.getSession();
        Emp_merchant ys_merchant = (Emp_merchant) session.getAttribute("ys_merchant");


        //查询返回所有商品,查询店铺物资
        List<Emp_object_pool> goods_pools = dateBase.object_poolToQuery
                ("select distinct object_pl.id,object_pl.cart_num,name,price,described " +
                        "from goods_pl left join object_pl on goods_pool="+ys_merchant.getGoods_pool()+
                        " and goods_pl.`cart_num`=object_pl.`cart_num`");

        //System.out.println(goods_pools.get(0));

        //储存商品数据
        session.setAttribute("goods_pools",goods_pools);
        request.setAttribute("state","just_0");
        request.getRequestDispatcher("/merchant.jsp").forward(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
