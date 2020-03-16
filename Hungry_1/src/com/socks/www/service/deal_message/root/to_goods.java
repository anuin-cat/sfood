package com.socks.www.service.deal_message.root;

import com.socks.www.dao.base.add;
import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_decision_pool_goods;
import com.socks.www.po.Emp_object_pool;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Arrays;
import java.util.List;

@WebServlet("/to_goods")
public class to_goods extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //标识
        System.out.println("-----to_goods-----");

        //判断类型并转发
        if("yes".equals(request.getParameter("operate"))){
            //审核通过，开始操作

            //获取审核通过的商品代号
            String[] carts = request.getParameterValues("carts");
            //System.out.println(Arrays.toString(carts));

            //逐个添加商品到物品池中，同时再商家店铺中添加商品的信息

            //物品池添加+记录删除
            for(String cart : carts) {
                //获取商品全部信息至decision类
                Emp_decision_pool_goods decision_object = dateBase.decision_pool_goodsToQuery(
                        "select * from decision_pl_goods where cart_num=" + cart).get(0);

                //获取正确的商品代号
                Integer cart_num = (Integer) dateBase.queryForObject("select max(cart_num) from object_pl",Integer.class);
                System.out.println(cart_num);

                //采集并转移信息,至object类
                Emp_object_pool object = new Emp_object_pool(
                        null,
                        cart_num+1,
                        decision_object.getName(),
                        decision_object.getPrice(),
                        decision_object.getDescribed()
                        );
                System.out.println(object);

                //存储到物品池中，同时添加至店铺池中
                add.addObject(decision_object.getGoods_pool()+"",object);

                //将记录从决策池中删除
                dateBase.DML(
                        "delete from decision_pl_goods where cart_num="+decision_object.getCart_num());
            }

            //设置状态，
            request.setAttribute("state","1");

            //刷新并返回root界面
            request.getRequestDispatcher("decision_goods_display0").forward(request,response);
        }

        if("no".equals(request.getParameter("operate"))){
            //审核未通过

            //获取审核未通过的商品代号
            String[] carts = request.getParameterValues("carts");
            //System.out.println(Arrays.toString(carts));

            //记录删除
            for(String cart : carts) {
                //将记录从决策池中删除
                dateBase.DML(
                        "delete from decision_pl_goods where cart_num=" + cart);
            }

            //设置状态，
            request.setAttribute("state","0");

            //刷新并返回root界面
            request.getRequestDispatcher("decision_goods_display0").forward(request,response);
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
