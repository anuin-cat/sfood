package com.socks.www.po;

/**
 * 管理员信息
 */
public class Emp_root {

    //编号
    private Integer id;

    //账号 + 密码
    private String account;
    private String password;

    //审批池代号
    private Integer decision_pool;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
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

    public Integer getDecision_pool() {
        return decision_pool;
    }

    public void setDecision_pool(Integer decision_pool) {
        this.decision_pool = decision_pool;
    }

    @Override
    public String toString() {
        return "Emp_root{" +
                "id=" + id +
                ", account='" + account + '\'' +
                ", password='" + password + '\'' +
                ", decision_pool=" + decision_pool +
                '}';
    }
}
