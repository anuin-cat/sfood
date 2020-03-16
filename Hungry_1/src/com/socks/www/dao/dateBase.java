package com.socks.www.dao;

import com.socks.www.po.*;
import com.socks.www.util.JDBCUtils;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

import java.util.List;

public class dateBase {
    //创建JDBCTemplate对象
    static JdbcTemplate template = new JdbcTemplate(JDBCUtils.getDataSource());

    //增删改操作
    public static int DML(String sql){
        if(sql!=null) {
            return dateBase.template.update(sql);
        }else{
            return -1;
        }
    }

    //类装载查询
    public static Object queryForObject(String sql,Class c){
        return template.queryForObject(sql,c);
    }

    //将user结果封装到query对象中
    public static List<Emp_user> userToQuery(String sql){
        if(sql!=null) {
            return dateBase.template.query(sql,new BeanPropertyRowMapper<Emp_user>(Emp_user.class));
        }else{
            return null;
        }
    }

    //将merchant结果封装到query对象中
    public static List<Emp_merchant> merchantToQuery(String sql){
        if(sql!=null) {
            return dateBase.template.query(sql,new BeanPropertyRowMapper<Emp_merchant>(Emp_merchant.class));
        }else{
            return null;
        }
    }

    //将root结果封装到query对象中
    public static List<Emp_root> rootToQuery(String sql){
        if(sql!=null) {
            return dateBase.template.query(sql,new BeanPropertyRowMapper<Emp_root>(Emp_root.class));
        }else{
            return null;
        }
    }

    //将cart_pool结果封装到query对象中
    public static List<Emp_cart_pool> cart_poolToQuery(String sql){
        if(sql!=null) {
            return dateBase.template.query(sql,new BeanPropertyRowMapper<Emp_cart_pool>(Emp_cart_pool.class));
        }else{
            return null;
        }
    }

    //将goods_pool结果封装到query对象中
    public static List<Emp_goods_pool> goods_poolToQuery(String sql){
        if(sql!=null) {
            return dateBase.template.query(sql,new BeanPropertyRowMapper<Emp_goods_pool>(Emp_goods_pool.class));
        }else{
            return null;
        }
    }

    //将order_pool结果封装到query对象中
    public static List<Emp_order_pool> order_poolToQuery(String sql){
        if(sql!=null) {
            return dateBase.template.query(sql,new BeanPropertyRowMapper<Emp_order_pool>(Emp_order_pool.class));
        }else{
            return null;
        }
    }

    //将decision_pool结果封装到query对象中
    public static List<Emp_decision_pool_user> decision_pool_userToQuery(String sql){
        if(sql!=null) {
            return dateBase.template.query(sql,new BeanPropertyRowMapper<Emp_decision_pool_user>(Emp_decision_pool_user.class));
        }else{
            return null;
        }
    }

    //将decision_pool结果封装到query对象中
    public static List<Emp_decision_pool_goods> decision_pool_goodsToQuery(String sql){
        if(sql!=null) {
            return dateBase.template.query(sql,new BeanPropertyRowMapper<Emp_decision_pool_goods>(Emp_decision_pool_goods.class));
        }else{
            return null;
        }
    }

    //将cart_pool结果封装到query对象中
    public static List<Emp_object_pool> object_poolToQuery(String sql){
        if(sql!=null) {
            return dateBase.template.query(sql,new BeanPropertyRowMapper<Emp_object_pool>(Emp_object_pool.class));
        }else{
            return null;
        }
    }

}
