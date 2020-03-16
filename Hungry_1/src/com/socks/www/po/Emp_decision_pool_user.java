package com.socks.www.po;

import java.sql.Date;

/**
 * 审批池
 */
public class Emp_decision_pool_user {
    //编号 + 审批池代号
    private Integer id;
    private Integer decision_pool;

    //账号 + 密码
    private String account;
    private String password;

    //提交时间
    private Date submit_time;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Integer getDecision_pool() {
        return decision_pool;
    }

    public void setDecision_pool(Integer decision_pool) {
        this.decision_pool = decision_pool;
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

    public Date getSubmit_time() {
        return submit_time;
    }

    public void setSubmit_time(Date submit_time) {
        this.submit_time = submit_time;
    }

    @Override
    public String toString() {
        return "Emp_decision_pool{" +
                "id=" + id +
                ", decision_pool=" + decision_pool +
                ", account='" + account + '\'' +
                ", password='" + password + '\'' +
                ", submit_time=" + submit_time +
                '}';
    }
}
