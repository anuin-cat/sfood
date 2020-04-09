package src.com.anuin.library.dao.base;

import src.com.anuin.library.bean.EmpEvaluate;
import src.com.anuin.library.bean.EmpOrder0;
import src.com.anuin.library.bean.EmpSeat;
import src.com.anuin.library.bean.EmpUser;

public class easyDML {

    /**
     * Evaluate操作
     * 增删改
     */

    //增加
    public static int evaluateInsert(EmpEvaluate adm){
        int dml = dataBase.DML("insert into evaluate values(" +
                adm.getId() + ",'" +
                adm.getContent() + "'," +
                adm.getGrade() + ",'" +
                adm.getTime() + "'," +
                adm.getIdUser() + "," +
                adm.getIdSeat() + "," +
                adm.getIdOrder0()+")"
        );
        return dml;
    }

    //删除
    public static int evaluateDelete(String name,String value,Class T){
        if(T==Integer.class){
            return dataBase.DML("delete from evaluate where "+name+"="+value);
        }else if(T==String.class){
            return dataBase.DML("delete from evaluate where "+name+"='"+value+"'");
        }else {
            return 0;
        }
    }

    //改变
    public static int evaluateUpdate(String name1,String value1,Class T1,String name2,String value2,Class T2){
        if(T1==Integer.class&&T2==Integer.class) {
            return
                    dataBase.DML("update evaluate set " + name2 + "=" + value2+" where "+name1+"="+value1);
        }else if(T1==Integer.class&&T2==String.class){
            return
                    dataBase.DML("update evaluate set " + name2 + "=" + value2+" where "+name1+"='"+value1+"'");
        }else if(T1==String.class&&T2==Integer.class){
            return
                    dataBase.DML("update evaluate set " + name2 + "='" + value2+"' where "+name1+"="+value1);
        }else if(T1==String.class&&T2==String.class){
            return
                    dataBase.DML("update evaluate set " + name2 + "='" + value2+"' where "+name1+"='"+value1+"'");
        }else {
            return 0;
        }
    }

    /**
     * Order操作
     * 增删改
     */

    //增加
    public static int orderInsert(EmpOrder0 adm){
        int dml = dataBase.DML("insert into order0 values(" +
                adm.getId() + ",'" +
                adm.getTimeStart() + "','" +
                adm.getTime() + "'," +
                adm.getIdUser() + "," +
                adm.getIdSeat()+")"
        );
        return dml;
    }

    //删除
    public static int orderDelete(String name,String value,Class T){
        if(T==Integer.class){
            return dataBase.DML("delete from order0 where "+name+"="+value);
        }else if(T==String.class){
            return dataBase.DML("delete from order0 where "+name+"='"+value+"'");
        }else {
            return 0;
        }
    }

    //改变
    public static int orderUpdate(String name1,String value1,Class T1,String name2,String value2,Class T2){
        if(T1==Integer.class&&T2==Integer.class) {
            return
                    dataBase.DML("update order0 set " + name2 + "=" + value2+" where "+name1+"="+value1);
        }else if(T1==Integer.class&&T2==String.class){
            return
                    dataBase.DML("update order0 set " + name2 + "=" + value2+" where "+name1+"='"+value1+"'");
        }else if(T1==String.class&&T2==Integer.class){
            return
                    dataBase.DML("update order0 set " + name2 + "='" + value2+"' where "+name1+"="+value1);
        }else if(T1==String.class&&T2==String.class){
            return
                    dataBase.DML("update order0 set " + name2 + "='" + value2+"' where "+name1+"='"+value1+"'");
        }else {
            return 0;
        }
    }


    /**
     * seat操作
     * 增删改
     */

    //增加
    public static int seatInsert(EmpSeat adm){
        int dml = dataBase.DML("insert into seat values(" +
                adm.getId() + "," +
                adm.getXposition() + "," +
                adm.getYposition() + ",'" +
                adm.getType() + "','" +
                adm.getSection() + "'," +
                adm.getGrade() + "," +
                adm.getCount() + "," +
                adm.getAppointment() + "," +
                adm.getFloor()+")"
        );
        return dml;
    }

    //删除
    public static int seatDelete(String name,String value,Class T){
        if(T==Integer.class){
            return dataBase.DML("delete from seat where "+name+"="+value);
        }else if(T==String.class){
            return dataBase.DML("delete from seat where "+name+"='"+value+"'");
        }else {
            return 0;
        }
    }

    //改变
    public static int seatUpdate(String name1,String value1,Class T1,String name2,String value2,Class T2){
        if(T1==Integer.class&&T2==Integer.class) {
            return
                    dataBase.DML("update seat set " + name2 + "=" + value2+" where "+name1+"="+value1);
        }else if(T1==Integer.class&&T2==String.class){
            return
                    dataBase.DML("update seat set " + name2 + "=" + value2+" where "+name1+"='"+value1+"'");
        }else if(T1==String.class&&T2==Integer.class){
            return
                    dataBase.DML("update seat set " + name2 + "='" + value2+"' where "+name1+"="+value1);
        }else if(T1==String.class&&T2==String.class){
            return
                    dataBase.DML("update seat set " + name2 + "='" + value2+"' where "+name1+"='"+value1+"'");
        }else {
            return 0;
        }
    }


    /**
     * user操作
     * 增删改
     */

    //增加
    public static int userInsert(EmpUser adm){
        int dml = dataBase.DML("insert into user values(" +
                adm.getId() + ",'" +
                adm.getAccount() + "','" +
                adm.getPassword() + "','" +
                adm.getIsBlack() + "','" +
                adm.getIdEvaluate() + "'," +
                adm.getIdOrder()+")"
        );
        return dml;
    }

    //删除
    public static int userDelete(String name,String value,Class T){
        if(T==Integer.class){
            return dataBase.DML("delete from user where "+name+"="+value);
        }else if(T==String.class){
            return dataBase.DML("delete from user where "+name+"='"+value+"'");
        }else {
            return 0;
        }
    }

    //改变
    public static int userUpdate(String name1,String value1,Class T1,String name2,String value2,Class T2){
        if(T1==Integer.class&&T2==Integer.class) {
            return
                    dataBase.DML("update user set " + name2 + "=" + value2+" where "+name1+"="+value1);
        }else if(T1==Integer.class&&T2==String.class){
            return
                    dataBase.DML("update user set " + name2 + "=" + value2+" where "+name1+"='"+value1+"'");
        }else if(T1==String.class&&T2==Integer.class){
            return
                    dataBase.DML("update user set " + name2 + "='" + value2+"' where "+name1+"="+value1);
        }else if(T1==String.class&&T2==String.class){
            return
                    dataBase.DML("update user set " + name2 + "='" + value2+"' where "+name1+"='"+value1+"'");
        }else {
            return 0;
        }
    }

}
