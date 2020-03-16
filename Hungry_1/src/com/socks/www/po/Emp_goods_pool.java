package com.socks.www.po;

/**
 * 店铺池
 */
public class Emp_goods_pool {

    //编号 + 店铺池代号 + 商品代号
    private Integer id;
    private Integer goods_pool;
    private Integer cart;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Integer getGoods_pool() {
        return goods_pool;
    }

    public void setGoods_pool(Integer goods_pool) {
        this.goods_pool = goods_pool;
    }

    public Integer getCart() {
        return cart;
    }

    public void setCart(Integer cart) {
        this.cart = cart;
    }

    @Override
    public String toString() {
        return "Emp_goods_pool{" +
                "id=" + id +
                ", goods_pool=" + goods_pool +
                ", cart=" + cart +
                '}';
    }
}
