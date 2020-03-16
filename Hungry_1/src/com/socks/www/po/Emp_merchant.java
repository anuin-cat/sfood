package com.socks.www.po;

/**
 * 商家信息
 */
public class Emp_merchant {
    //编号 + 昵称
    private Integer id;
    private String name;

    //账号 + 密码
    private String account;
    private String password;

    //余额
    private Integer balance;

    //店铺池代号 + 订单池代号
    private Integer goods_pool;
    private Integer order_pool;


    public Emp_merchant(Integer id, String name, String account, String password, Integer balance, Integer goods_pool, Integer order_pool) {
        this.id = id;
        this.name = name;
        this.account = account;
        this.password = password;
        this.balance = balance;
        this.goods_pool = goods_pool;
        this.order_pool = order_pool;
    }

    public Emp_merchant(){ }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAccount() {
        return account;
    }

    public void setAccount(String account) {
        this.account = account;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public Integer getBalance() {
        return balance;
    }

    public void setBalance(Integer balance) {
        this.balance = balance;
    }

    public Integer getGoods_pool() {
        return goods_pool;
    }

    public void setGoods_pool(Integer goods_pool) {
        this.goods_pool = goods_pool;
    }

    public Integer getOrder_pool() {
        return order_pool;
    }

    public void setOrder_pool(Integer order_pool) {
        this.order_pool = order_pool;
    }

    @Override
    public String toString() {
        return "Emp_merchant{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", account='" + account + '\'' +
                ", password='" + password + '\'' +
                ", balance=" + balance +
                ", goods_pool=" + goods_pool +
                ", order_pool=" + order_pool +
                '}';
    }
}
