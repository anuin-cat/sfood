package src.com.anuin.library.service.connect;

import src.com.anuin.library.bean.EmpUser;
import src.com.anuin.library.dao.base.easyObject;
import src.com.anuin.library.dao.base.easyQuery;
import src.com.anuin.library.entity.EntUser;

import java.util.List;

public class Login {
    //登录检查
    public static String login(EmpUser user){

        //管理员检测
        if(user.getAccount().equals("root")&&user.getPassword().equals("root")){
            return "root";
        }


        //用户检测
        int count = easyObject.count(
                "user",
                "account", user.getAccount(), String.class,
                "password", user.getPassword(), String.class
        );
        if(count!=0){
            //获取用户集合
            List<EmpUser> users = easyQuery.easyUser("account", user.getAccount(), String.class);
            //全局变量装载用户信息
            EmpUser U = new EmpUser();
            EntUser.id = U.getId();
            EntUser.account = U.getAccount();
            EntUser.password = U.getPassword();
            EntUser.idOrder = U.getIdOrder();
            EntUser.idEvaluate = U.getIdEvaluate();
            EntUser.isBlack = U.getIsBlack();
            return "user";
        }else {
            return "empty";
        }
    }
}
