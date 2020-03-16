package com.socks.www.dao;

public class check {
    public static boolean checkAccount(String account){
        System.out.println("到达checkAccount");
        Integer o = (Integer) dateBase.queryForObject("select count(account) from user where account=" + "'"+account+ "'", Integer.class);
        if(o!=0){
            return true;
        }else {
            return false;
        }
    }
}
