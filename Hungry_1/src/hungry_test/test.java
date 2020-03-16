package hungry_test;

import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_user;
import org.junit.Test;

import java.util.List;

public class test {
    @Test //杂
    public void test_1(){
        System.out.println(
            dateBase.DML("insert into xiaoming values(19,'小xiao','2026-06-22')")
        );
    }

    @Test   //用户
    public void test_2(){
        System.out.println(
                dateBase.userToQuery("select * from user")
        );
        List<Emp_user> user = dateBase.userToQuery("select * from user");
    }

    @Test   //商家
    public void test_3(){
        System.out.println(
                dateBase.merchantToQuery("select * from merchant")
        );
    }

    @Test   //管理员
    public void test_4(){
        System.out.println(
                dateBase.rootToQuery("select * from root")
        );
    }

    @Test   //购物车 + 注意取子时索引的取值
    public void test_5(){
        System.out.println(
                dateBase.cart_poolToQuery("select * from cart_pl")//.get(0).getCart_num()+" "
        );
    }

    @Test   //店铺池
    public void test_6(){
        System.out.println(
                dateBase.goods_poolToQuery("select * from goods_pl")
        );
    }

    @Test   //订单池
    public void test_7(){
        System.out.println(
                dateBase.order_poolToQuery("select * from order_pl")
        );
    }

    @Test   //用户审批池
    public void test_8(){
        System.out.println(
                dateBase.decision_pool_userToQuery("select * from decision_pl_user")
        );
    }

    @Test   //商品审批池
    public void test_9(){
        System.out.println(
                dateBase.decision_pool_goodsToQuery("select * from decision_pl_goods")
        );
    }

    @Test   //商品池
    public void test_10(){
        System.out.println(
                dateBase.object_poolToQuery("select * from object_pl")
        );
    }

}
