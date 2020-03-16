package com.socks.www.dao.base;

import com.socks.www.dao.dateBase;
import com.socks.www.po.*;

import java.text.SimpleDateFormat;
import java.util.Date;

public class add {

    //添加用户信息
    public static int addUser(Emp_user user){
        System.out.println("调用了add方法");
        int cart_pool = (int) dateBase.queryForObject("SELECT MAX(cart_pool) FROM USER",Integer.class)+1;
        dateBase.DML("insert into user values (" +
                "null, "+
                "'"+user.getName()+"', "+
                "'"+user.getAccount()+"', " +
                "'"+user.getPassword()+"', " +
                "0, " +
                cart_pool+
                ")");
        return 0;
    }

    //添加商家信息，正版
    public static int addMerchant(Emp_merchant merchant){

        return 0;
    }

    //添加商家信息，重载
    public static int addMerchant(Emp_user user){
        //Emp_merchant merchant = new Emp_merchant();

        int num = (Integer)dateBase.queryForObject("select max(goods_pool) from merchant",Integer.class)+1;

        dateBase.DML("insert into merchant values("+
                        "null,"+
                        "'"+user.getName()+"',"+
                        "'"+user.getAccount()+"',"+
                        "'"+user.getPassword()+"',"+
                        user.getBalance()+","+
                        num+","+
                        num+")"
        );

        return 0;
    }

    //添加商品信息
    public static int addObject(String goods_pool, Emp_object_pool object_pool){
        System.out.println("调用了add方法");
        Integer cart_num = (Integer) dateBase.queryForObject("select max(cart_num) from object_pl",Integer.class);

        //特殊情况判断
        if("null".equals(cart_num+"")){
            cart_num=1;
        }

        int a=cart_num+1;

        dateBase.DML("insert into object_pl values(" +
                "null," +
                a +
                ",'" +object_pool.getName() +"'," +
                object_pool.getPrice()+
                ",'" +object_pool.getDescribed() +"')"
        );
        dateBase.DML("insert into goods_pl values("+
                "null," +
                goods_pool +","+
                object_pool.getCart_num()+")"
        );

        return 0;
    }

    //添加审批池商品信息
    public static int addDecisionGoods(Emp_decision_pool_goods goods){
        //获取当前日期
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
        String d =sdf.format(new Date());

        Integer goods_num = (Integer) dateBase.queryForObject("select max(cart_num) from decision_pl_goods",Integer.class);

        //特殊情况判断
        if("null".equals(goods_num+"")){
            goods_num=1;
        }
        dateBase.DML("insert into decision_pl_goods values(1,"+
                goods_num+1 +","+
                "'" +goods.getName()+"'," +
                goods.getPrice() +
                ",'" +goods.getDescribed()+"',"+
                "'"+d+"',"+
                goods.getGoods_pool()+")"
        );

        return 0;
    }

    //添加审批池用户信息
    public static int addDecisionUser(Emp_user user){
        //获取当前日期
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
        String d =sdf.format(new Date());

        Integer user_num = (Integer) dateBase.queryForObject("select max(decision_pool) from decision_pl_user",Integer.class);

        //特殊情况判断
        if("null".equals(user_num+"")){
            user_num=1;
        }

        //存储用户信息
        dateBase.DML("insert into decision_pl_user values("+
                        "null,"+
                        user_num+
                        ",'"+user.getAccount()+"',"+
                        "'"+user.getPassword()+"',"+
                        "'"+d+"')"
                );

        return 0;
    }
}



























