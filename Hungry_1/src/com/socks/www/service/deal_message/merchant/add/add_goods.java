package com.socks.www.service.deal_message.merchant.add;

import com.socks.www.dao.base.add;
import com.socks.www.po.Emp_decision_pool_goods;
import com.socks.www.po.Emp_merchant;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/add_goods")
public class add_goods extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //创建待上架商品的信息
        Emp_decision_pool_goods goods = new Emp_decision_pool_goods();
        Emp_merchant merchant = (Emp_merchant) request.getSession().getAttribute("ys_merchant");

        //获取表单数据
        String name = request.getParameter("name");
        Integer price = Integer.valueOf(request.getParameter("price"));
        String described = request.getParameter("described");

        //特殊情况判断
        if((null!=name)&&(null!=described)&&(null!=price)){
            //正常情况
            goods.setName(name);
            goods.setDescribed(described);
            goods.setGoods_pool(merchant.getGoods_pool());
            goods.setPrice(price);
        }else {
            //输入数据有误
            request.setAttribute("state","no3");
            request.getRequestDispatcher("merchant_add_goods.jsp").forward(request,response);
        }

        System.out.println(goods+"  "+name+"  "+price);

        //添加待上架商品
        add.addDecisionGoods(goods);

        //转发到商品添加页面
        request.setAttribute("state","yes");
        request.getRequestDispatcher("merchant_add_goods.jsp").forward(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
