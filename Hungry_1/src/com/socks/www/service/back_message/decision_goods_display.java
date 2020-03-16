package com.socks.www.service.back_message;

import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_decision_pool_goods;
import com.socks.www.po.Emp_merchant;
import com.socks.www.po.Emp_object_pool;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

@WebServlet("/decision_goods_display")
public class decision_goods_display extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //标识
        System.out.println("-----decision_goods_display-----");

        //创建session对象+接收商家账号信息
        HttpSession session = request.getSession();
        Emp_merchant ys_merchant = (Emp_merchant) session.getAttribute("ys_merchant");

        //查询商家提交的上架商品的信息
        List<Emp_decision_pool_goods> decision_pool_goods = dateBase.decision_pool_goodsToQuery
                ("select * from decision_pl_goods where goods_pool="+ys_merchant.getGoods_pool());

        //存储商品信息
        session.setAttribute("decision_goods",decision_pool_goods);
        request.setAttribute("state","just_1");
        request.getRequestDispatcher("/merchant_add_goods.jsp").forward(request,response);

        System.out.println(decision_pool_goods);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}

















