package com.socks.www.po;

import java.sql.Date;

/**
 *订单池
 */
public class Emp_order_pool {

    //编号
    private Integer id;

    //订单池代号 + 购物车代号
    private Integer order_pool;
    private Integer cart_pool;

    //提交时间
    private Date submit_time;
    private Integer cart_num;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Integer getOrder_pool() {
        return order_pool;
    }

    public void setOrder_pool(Integer order_pool) {
        this.order_pool = order_pool;
    }

    public Integer getCart_pool() {
        return cart_pool;
    }

    public void setCart_pool(Integer cart_pool) {
        this.cart_pool = cart_pool;
    }

    public Date getSubmit_time() {
        return submit_time;
    }

    public void setSubmit_time(Date submit_time) {
        this.submit_time = submit_time;
    }

    public Integer getCart_num() {
        return cart_num;
    }

    public void setCart_num(Integer cart_num) {
        this.cart_num = cart_num;
    }

    @Override
    public String toString() {
        return "Emp_order_pool{" +
                "id=" + id +
                ", order_pool=" + order_pool +
                ", cart_pool=" + cart_pool +
                ", submit_time=" + submit_time +
                ", cart_num=" + cart_num +
                '}';
    }
}
