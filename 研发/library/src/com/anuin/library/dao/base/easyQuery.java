package src.com.anuin.library.dao.base;

import src.com.anuin.library.bean.EmpEvaluate;
import src.com.anuin.library.bean.EmpOrder0;
import src.com.anuin.library.bean.EmpSeat;
import src.com.anuin.library.bean.EmpUser;

import java.util.List;

public class easyQuery {
    /**
     *  evaluate操作
     */

    //返回对应集合
    public static List<EmpEvaluate> easyEvaluate(String name, String value, Class T){
        if(T==Integer.class){
            return dataBase.queryForEvaluate("select * from evaluate where "+name+"="+value);
        }else if(T==String.class){
            return dataBase.queryForEvaluate("select * from evaluate where "+name+"='"+value+"'");
        }else {
            return null;
        }
    }

    public static List<EmpEvaluate> easyEvaluate(){
        return dataBase.queryForEvaluate("select * from evaluate");
    }

    /**
     *  order0操作
     */

    //返回对应集合
    public static List<EmpOrder0> easyOrder(String name, String value, Class T){
        if(T==Integer.class){
            return dataBase.queryForOrder("select * from order0 where "+name+"="+value);
        }else if(T==String.class){
            return dataBase.queryForOrder("select * from order0 where "+name+"='"+value+"'");
        }else {
            return null;
        }
    }

    public static List<EmpOrder0> easyOrder(String name1, String value1, Class T1, String name2, String value2, Class T2){
        if(T1==Integer.class&&T2==Integer.class){
            return dataBase.queryForOrder("select * from order0 where "+name1+"="+value1+" and "+name2+"="+value2);
        }else if(T1==Integer.class&&T2==String.class){
            return dataBase.queryForOrder("select * from order0 where "+name1+"="+value1+" and "+name2+"='"+value2+"'");
        }else if(T1==String.class&&T2==Integer.class){
            return dataBase.queryForOrder("select * from order0 where "+name1+"='"+value1+"' and "+name2+"="+value2);
        }else if(T1==String.class&&T2==String.class){
            return dataBase.queryForOrder("select * from order0 where "+name1+"='"+value1+"' and "+name2+"='"+value2+"'");
        }else {
            return null;
        }
    }

    public static List<EmpOrder0> easyOrder(){
        return dataBase.queryForOrder("select * from order0");
    }


    /**
     *  seat操作
     */

    //返回对应集合
    public static List<EmpSeat> easySeat(String name, String value, Class T){
        if(T==Integer.class){
            return dataBase.queryForSeat("select * from seat where "+name+"="+value);
        }else if(T==String.class){
            return dataBase.queryForSeat("select * from seat where "+name+"='"+value+"'");
        }else {
            return null;
        }
    }

    public static List<EmpSeat> easySeat(String name1, String value1, Class T1,String name2, String value2, Class T2){
        if(T1==Integer.class&&T2==Integer.class){
            return dataBase.queryForSeat("select * from seat where "+name1+"="+value1+" and "+name2+"="+value2);
        }else if(T1==Integer.class&&T2==String.class){
            return dataBase.queryForSeat("select * from seat where "+name1+"="+value1+" and "+name2+"='"+value2+"'");
        }else if(T1==String.class&&T2==Integer.class){
            return dataBase.queryForSeat("select * from seat where "+name1+"='"+value1+"' and "+name2+"="+value2);
        }else if(T1==String.class&&T2==String.class){
            return dataBase.queryForSeat("select * from seat where "+name1+"='"+value1+"' and "+name2+"='"+value2+"'");
        }else {
            return null;
        }
    }

    public static List<EmpSeat> easySeat(String name1, String value1, Class T1,String name2, String value2, Class T2,String floor){
        if(T1==Integer.class&&T2==Integer.class){
            return dataBase.queryForSeat("select * from seat where "+name1+"="+value1+" and "+name2+"="+value2+" and floor="+floor);
        }else if(T1==Integer.class&&T2==String.class){
            return dataBase.queryForSeat("select * from seat where "+name1+"="+value1+" and "+name2+"='"+value2+"' and floor="+floor);
        }else if(T1==String.class&&T2==Integer.class){
            return dataBase.queryForSeat("select * from seat where "+name1+"='"+value1+"' and "+name2+"="+value2+" and floor="+floor);
        }else if(T1==String.class&&T2==String.class){
            return dataBase.queryForSeat("select * from seat where "+name1+"='"+value1+"' and "+name2+"='"+value2+"' and floor="+floor);
        }else {
            return null;
        }
    }

    public static List<EmpSeat> easySeat(){
        return dataBase.queryForSeat("select * from seat");
    }



    /**
     *  user操作
     */

    //返回对应集合
    public static List<EmpUser> easyUser(String name, String value, Class T){
        if(T==Integer.class){
            return dataBase.queryForUser("select * from user where "+name+"="+value);
        }else if(T==String.class){
            return dataBase.queryForUser("select * from user where "+name+"='"+value+"'");
        }else {
            return null;
        }
    }

    public static List<EmpUser> easyUser(){
        return dataBase.queryForUser("select * from user");
    }

}
