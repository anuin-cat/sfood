package src.com.anuin.service;

import src.com.anuin.bean.EmpInstruct;
import src.com.anuin.dao.base.database;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class dataBase {
    public static void save(String content){
        //获取当前日期
        String date  = (new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date()));
        database.DML("insert into instruct values(null,'"+content+"','"+date+"')");
    }

    public static List<EmpInstruct> extract(){
        //获取所有历史输入数据
        List<EmpInstruct> Instructs = database.queryForInstruct("select * from instruct");

        return Instructs;
    }

}
