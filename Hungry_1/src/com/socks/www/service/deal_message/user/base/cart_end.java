package com.socks.www.service.deal_message.user.base;

import com.socks.www.dao.base.time;
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

@WebServlet("/cart_end")
public class cart_end extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        System.out.println("-----cart_end-----");
        //创建session对象
        HttpSession session = request.getSession();
        Emp_user ys_user = (Emp_user) session.getAttribute("ys_user");

        //查询返回所有商品,查询购物车
        List<Emp_object_pool> cart_pool = dateBase.object_poolToQuery
                ("select distinct object_pl.id,object_pl.cart_num,name,price,described " +
                        "from cart_pl left join object_pl on cart_pool="+ys_user.getCart_pool()+
                        " and cart_pl.`cart_num`=object_pl.`cart_num`");

        //总结所有商品的价格
        int sum = 0;
        for(Emp_object_pool object : cart_pool){
            sum += object.getPrice();
        }

        //判断总价是否超过用户账户金额
        if(sum > ys_user.getBalance()){
            //用户余额不足
            System.out.println("用户金额不足");
            request.setAttribute("state","no1");
            request.getRequestDispatcher("user.jsp").forward(request,response);
        }else {
            //从用户的账户扣除所需金额
            System.out.println("扣除金额:"+sum);
            dateBase.DML("update user set balance=balance-"+sum+" where account='"+ys_user.getAccount()+"'");

            //逐个将商品的码存储到对应的商家的订单池中
            for(Emp_object_pool object:cart_pool){

                //获取商家订单池对象（池中包含这个商品的商品代码）(获取的是商家的店铺池对象)
                List<Emp_goods_pool> goods_pools = dateBase.goods_poolToQuery(
                        "select * from goods_pl where cart_num=" + object.getCart_num());


                //获取店铺池编号，并通过编号获取商家信息
                List<Emp_merchant> merchants = dateBase.merchantToQuery(
                        "select * from merchant where goods_pool=" + goods_pools.get(0).getGoods_pool());

                //将对应的信息存储到商家的订单池中
                dateBase.DML(
                        "insert order_pl values (null,"+
                                merchants.get(0).getOrder_pool()+
                                ","+ys_user.getCart_pool()+
                                ",'"+ time.backTime()+
                                "',"+object.getCart_num()+")"
                );
            }

            //刷新账户信息
            List<Emp_user> user = dateBase.userToQuery("select * from user where account=" + ys_user.getAccount());
            request.getSession().setAttribute("ys_user",user.get(0));

            //转发
            request.setAttribute("state","yes1");
            request.getRequestDispatcher("user.jsp").forward(request,response);
        }



    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
