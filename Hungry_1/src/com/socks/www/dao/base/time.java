package com.socks.www.dao.base;

import java.sql.Date;
import java.text.SimpleDateFormat;

public class time {
    public static String backTime(){
        //获取当前日期
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
        return sdf.format(new java.util.Date());
    }
}
