package src.com.anuin.library.service.user;

import src.com.anuin.library.bean.EmpOrder0;
import src.com.anuin.library.dao.base.easyQuery;
import src.com.anuin.library.entity.EntSeat;
import src.com.anuin.library.view.Ent.EntView;

import java.util.List;

public class userCheck {
    //检测这个座位的本能限制
    public static Boolean checkIsUsed(String s){

        String section = EntSeat.section;

        if(section==null){
            return false;
        }

        if(section.contains(","+s+",")){
            return true;
        }else {
            return false;
        }
    }

    //检测这个座位的在这个时间是否被预约
    public static Boolean checkIsTimeOrder(String time){
        List<EmpOrder0> Orders = easyQuery.easyOrder(
                "id_seat", EntSeat.id + "", Integer.class, "time_start", EntView.EntDate.getValue() + "", String.class
        );
        if (Orders.size() != 0) {
            for (EmpOrder0 order : Orders) {
                if (order.getTime().contains("," + time + ",")) {
                    return true;
                }
            }
        }
        return false;
    }

}
