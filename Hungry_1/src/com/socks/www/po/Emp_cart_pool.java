package com.socks.www.po;

/**
 * 购物车
 */
public class Emp_cart_pool {

    //编号 + 商品代号 + 购物车代号
    private Integer cart_num;
    private Integer cart_pool;

    public Integer getCart_num() {
        return cart_num;
    }

    public void setCart_num(Integer cart_num) {
        this.cart_num = cart_num;
    }

    public Integer getCart_pool() {
        return cart_pool;
    }

    public void setCart_pool(Integer cart_pool) {
        this.cart_pool = cart_pool;
    }

    @Override
    public String toString() {
        return "Emp_cart_pool{" +
                "cart_num=" + cart_num +
                ", cart_pool=" + cart_pool +
                '}';
    }
}
