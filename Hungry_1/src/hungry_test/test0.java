package hungry_test;

import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_user;
import com.socks.www.util.JDBCUtils;
import org.junit.Test;
import org.springframework.jdbc.core.JdbcTemplate;

import javax.servlet.http.Cookie;
import java.text.SimpleDateFormat;
import java.util.Date;


public class test0 {
    public  String a ;
    public String mm() {
        return dateBase.cart_poolToQuery("select * from cart_pl").get(0).getCart_num()+" ";
    }

    @Test
    public void mmm(){
        ;
    }
    @Test
    public void sss(){
        Emp_user user = new Emp_user(0,"小明","159","85265",5,0);
        int cart_pool = (int)dateBase.queryForObject("SELECT MAX(cart_pool) FROM USER",Integer.class)+1;
        dateBase.DML("insert into user values (" +
                "null, "+
                "'"+user.getName()+"', "+
                "'"+user.getAccount()+"', " +
                "'"+user.getPassword()+"', " +
                "0, " +
                cart_pool+
                ")");
    }

    @Test
    public void test6(){
//获取当前日期
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
        String d =sdf.format(new Date());

        System.out.println(d);
    }
    @Test
    public void checkAccount(){
        String account;
        account = "193349456";
        Object o = dateBase.queryForObject("select account from user where account=" + account, String.class);
        if(o!=null){
            System.out.println("true");
            //return true;
        }else {
            System.out.println("false");
            //return false;
        }
    }


}
