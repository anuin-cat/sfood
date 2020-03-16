package com.socks.www.po;

import java.sql.Date;

public class Emp_decision_pool_goods {
    //决策池代号
    private Integer decision_pool;

    //商品信息
    private Integer cart_num;
    private String name;
    private Integer price;
    private String described;
    private Date submit_time;
    private Integer goods_pool;

    public Integer getDecision_pool() {
        return decision_pool;
    }

    public void setDecision_pool(Integer decision_pool) {
        this.decision_pool = decision_pool;
    }

    public Integer getCart_num() {
        return cart_num;
    }

    public void setCart_num(Integer cart_num) {
        this.cart_num = cart_num;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Integer getPrice() {
        return price;
    }

    public void setPrice(Integer price) {
        this.price = price;
    }

    public String getDescribed() {
        return described;
    }

    public void setDescribed(String described) {
        this.described = described;
    }

    public Date getSubmit_time() {
        return submit_time;
    }

    public void setSubmit_time(Date submit_time) {
        this.submit_time = submit_time;
    }

    public Integer getGoods_pool() {
        return goods_pool;
    }

    public void setGoods_pool(Integer goods_pool) {
        this.goods_pool = goods_pool;
    }

    @Override
    public String toString() {
        return "Emp_decision_pool_goods{" +
                "decision_pool=" + decision_pool +
                ", cart_num=" + cart_num +
                ", name='" + name + '\'' +
                ", price=" + price +
                ", described='" + described + '\'' +
                ", submit_time=" + submit_time +
                ", goods_pool=" + goods_pool +
                '}';
    }
}
