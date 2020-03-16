package com.socks.www.dao.base;

import com.mysql.cj.PreparedQuery;
import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_user;

import java.util.List;

public class delete {
    //删除商品信息
    public static int deleteGoods(String goods_pool,String cart_num){
        //int cart_num = (int) dateBase.queryForObject("select cart_num from object_num where name="+"'"+name+"'",Integer.class);
        dateBase.DML("delete from goods_pl where goods_pool="+goods_pool+" and cart_num="+cart_num);
        return 0;
    }

    //将商品移出购物车
    public static int removeCart(String cart_pool,String cart_num){

        dateBase.DML("delete from cart_pl where cart_pool="+cart_pool+" and cart_num="+cart_num);
        return 0;
    }

    //删除决策库中的信息
    public static int removeDecisionUser(String account){
        dateBase.DML("delete from decision_pl_user where account='"+account+"'");
        return 0;
    }

    //删除用户信息
    public static int removeUser(String account){
        //获取用户信息
        List<Emp_user> user = dateBase.userToQuery("select * from user where account=" + account);

        //删除购物车信息
        dateBase.DML("delete from cart_pl where cart_pool="+user.get(0).getCart_pool());

        //删除个人信息
        dateBase.DML("delete from user where account='"+account+"'");
        return 0;
    }

}
