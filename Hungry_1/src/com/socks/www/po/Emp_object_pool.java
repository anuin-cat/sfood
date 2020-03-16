package com.socks.www.po;


/**
 * 商品池
 */
public class Emp_object_pool {
    //编号
    private Integer id;

    //商品代号 + 商品名称
    private Integer cart_num;
    private String name;

    //商品价格 + 商品描述
    private Integer price;
    private String described;

    public Emp_object_pool(){

    }

    public Emp_object_pool(Integer id, Integer cart_num, String name, Integer price, String described) {
        this.id = id;
        this.cart_num = cart_num;
        this.name = name;
        this.price = price;
        this.described = described;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
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

    @Override
    public String toString() {
        return "Emp_object_pool{" +
                "id=" + id +
                ", cart_num=" + cart_num +
                ", name='" + name + '\'' +
                ", price=" + price +
                ", described='" + described + '\'' +
                '}';
    }
}
