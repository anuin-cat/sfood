package com.socks.www.po;

/**
 * 用户信息
 */
public class Emp_user {

    //编号 + 昵称
    private Integer id;
    private String name;

    //账号 + 密码
    private String account;
    private String password;

    //余额 + 购物车代号
    private Integer balance;
    private Integer cart_pool;

    public Emp_user() {
    }

    public Emp_user(Integer id, String name, String account, String password, Integer balance, Integer cart_pool) {
        this.id = id;
        this.name = name;
        this.account = account;
        this.password = password;
        this.balance = balance;
        this.cart_pool = cart_pool;
    }

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

    public Integer getCart_pool() {
        return cart_pool;
    }

    public void setCart_pool(Integer cart_pool) {
        this.cart_pool = cart_pool;
    }

    @Override
    public String toString() {
        return "Emp_user{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", account='" + account + '\'' +
                ", password='" + password + '\'' +
                ", balance=" + balance +
                ", cart_pool=" + cart_pool +
                '}';
    }
}
