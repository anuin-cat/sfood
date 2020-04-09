package src.com.anuin.library.service.connect;

import src.com.anuin.library.bean.EmpUser;
import src.com.anuin.library.dao.base.easyObject;

public class Register {
    public static String checkAccount(String account){
        //获取账号是否存在
        Integer count;
        count = easyObject.count("user","account",account,String.class);

        if(count!=0){
            return "YES";
        }else {
            return "NO";
        }
    }
}
