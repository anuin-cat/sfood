package com.socks.www.dao.base;

import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_goods_pool;
import com.socks.www.po.Emp_object_pool;

public class change {
    public static int changeGoods(String cart_num, Emp_object_pool object){
        dateBase.DML(
                "update goods_pl set name="+object.getName()+",price="+object.getPrice()+",described="+object.getDescribed()+
                        " where cart_num="+cart_num
        );

        return 0;
    }
}
