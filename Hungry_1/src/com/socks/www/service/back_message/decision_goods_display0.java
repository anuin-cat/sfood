package com.socks.www.service.back_message;

import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_decision_pool_goods;
import com.socks.www.po.Emp_merchant;
import com.socks.www.po.Emp_root;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

@WebServlet("/decision_goods_display0")
public class decision_goods_display0 extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //标识
        System.out.println("-----decision_goods_display0-----");

        //查询上架商品池的信息
        List<Emp_decision_pool_goods> decision_pool_goods = dateBase.decision_pool_goodsToQuery
                ("select * from decision_pl_goods");

        System.out.println(decision_pool_goods);

        //存储商品信息
        request.getSession().setAttribute("decision_goods",decision_pool_goods);
        request.setAttribute("state","just_1");
        request.getRequestDispatcher("/decision_user_display").forward(request,response);

        System.out.println(decision_pool_goods);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
