package src.com.anuin.library.dao.base;

import src.com.anuin.library.bean.EmpEvaluate;
import src.com.anuin.library.bean.EmpOrder0;
import src.com.anuin.library.bean.EmpSeat;
import src.com.anuin.library.bean.EmpUser;
import src.com.anuin.library.util.JDBCUtils;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class dataBase {
    //增删改语句
    public static int DML(String sql){

        Connection conn = null;
        Statement stmt = null;
        int count = 0;
        try {
            //获取连接
            conn = JDBCUtils.getConnection();
            //获取执行对象
            stmt = conn.createStatement();
            //执行sql
            count = stmt.executeUpdate(sql);
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JDBCUtils.close(stmt,conn);
        }
        //返回状态
        return count;
    }

    //简单查询ForObject
    public static <T> T queryForObject(String sql,Class T){
        Connection conn = null;
        Statement stmt = null;
        T t = null;
        try {
            //获取连接
            conn = JDBCUtils.getConnection();
            //获取执行对象
            stmt = conn.createStatement();
            //执行sql
            ResultSet rs = stmt.executeQuery(sql);
            while (rs.next()){
                t= (T) rs.getString(1);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JDBCUtils.close(stmt,conn);
        }
        //返回状态
        return t;
    }


    //获取user
    public static List<EmpUser> queryForUser(String sql){

        List<EmpUser> adm = new ArrayList<>();
        EmpUser emp = null;

        Connection conn = null;
        Statement stmt = null;
        try {
            //获取连接
            conn = JDBCUtils.getConnection();
            //获取执行对象
            stmt = conn.createStatement();
            //执行sql
            ResultSet rs = stmt.executeQuery(sql);
            //遍历并装
            while (rs.next()){
                emp = new EmpUser();
                emp.setId(rs.getInt("id"));
                emp.setAccount(rs.getString("account"));
                emp.setIdOrder(rs.getInt("id_order"));
                emp.setIdEvaluate(rs.getInt("id_evaluate"));
                emp.setPassword(rs.getString("password"));
                emp.setIsBlack(rs.getString("is_black"));
                adm.add(emp);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JDBCUtils.close(stmt,conn);
        }

        return adm;
    }

    //获取Order
    public static List<EmpOrder0> queryForOrder(String sql){

        List<EmpOrder0> adm = new ArrayList<>();
        EmpOrder0 emp = null;

        Connection conn = null;
        Statement stmt = null;
        try {
            //获取连接
            conn = JDBCUtils.getConnection();
            //获取执行对象
            stmt = conn.createStatement();
            //执行sql
            ResultSet rs = stmt.executeQuery(sql);
            //遍历并装
            while (rs.next()){
                emp = new EmpOrder0();
                emp.setId(rs.getInt("id"));
                emp.setIdSeat(rs.getInt("id_seat"));
                emp.setIdUser(rs.getInt("id_user"));
                emp.setTime(rs.getString("time"));
                emp.setTimeStart(rs.getDate("time_start"));
                adm.add(emp);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JDBCUtils.close(stmt,conn);
        }

        return adm;
    }

    //获取Evaluate
    public static List<EmpEvaluate> queryForEvaluate(String sql){

        List<EmpEvaluate> adm = new ArrayList<>();
        EmpEvaluate emp = null;

        Connection conn = null;
        Statement stmt = null;
        try {
            //获取连接
            conn = JDBCUtils.getConnection();
            //获取执行对象
            stmt = conn.createStatement();
            //执行sql
            ResultSet rs = stmt.executeQuery(sql);
            //遍历并装
            while (rs.next()){
                emp = new EmpEvaluate();
                emp.setContent(rs.getString("content"));
                emp.setIdSeat(rs.getInt("id_seat"));
                emp.setIdUser(rs.getInt("id_user"));
                emp.setTime(rs.getDate("time"));
                emp.setGrade(rs.getInt("grade"));
                emp.setId(rs.getInt("id"));
                emp.setIdOrder0(rs.getInt("id_order"));
                adm.add(emp);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JDBCUtils.close(stmt,conn);
        }

        return adm;
    }

    //获取Seat
    public static List<EmpSeat> queryForSeat(String sql){

        List<EmpSeat> adm = new ArrayList<>();
        EmpSeat emp = null;

        Connection conn = null;
        Statement stmt = null;
        try {
            //获取连接
            conn = JDBCUtils.getConnection();
            //获取执行对象
            stmt = conn.createStatement();
            //执行sql
            ResultSet rs = stmt.executeQuery(sql);
            //遍历并装
            while (rs.next()){
                emp = new EmpSeat();
                emp.setAppointment(rs.getInt("appointment"));
                emp.setCount(rs.getInt("count"));
                emp.setFloor(rs.getInt("floor"));
                emp.setSection(rs.getString("section"));
                emp.setGrade(rs.getInt("grade"));
                emp.setId(rs.getInt("id"));
                emp.setType(rs.getString("type"));
                emp.setXposition(rs.getInt("Xposition"));
                emp.setYposition(rs.getInt("Yposition"));
                adm.add(emp);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JDBCUtils.close(stmt,conn);
        }

        return adm;
    }

}
