package src.com.anuin.dao.base;

import src.com.anuin.bean.EmpInstruct;
import src.com.anuin.util.JDBCUtils;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class database {
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


    //获取Instruct
    public static List<EmpInstruct> queryForInstruct(String sql){

        List<EmpInstruct> adm = new ArrayList<>();
        EmpInstruct emp = null;

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
                emp = new EmpInstruct();
                emp.setId(rs.getInt("id"));
                emp.setContent(rs.getString("content"));
                emp.setTime(rs.getTimestamp("time"));
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
