package src.com.anuin.library.view.aside;

import src.com.anuin.library.bean.EmpSeat;
import src.com.anuin.library.dao.base.easyDML;
import src.com.anuin.library.dao.base.easyObject;

public class creatData {
    public static void creatSeatss(Integer floor){
        EmpSeat seat;

        for (int i=0;i<12;i++){
            for(int j=0;j<12;j++){
                seat = new EmpSeat();
                int maxId = easyObject.max("seat", "id");

                seat.setId(maxId+1);
                seat.setXposition(i);
                seat.setYposition(j);
                seat.setType("普通座");
                seat.setFloor(floor);
                seat.setAppointment(7);
                seat.setSection(",7,8,9,10,11,12,13,14,15,16,17,18,19,20,");
                seat.setGrade(8);
                seat.setCount(1);

                easyDML.seatInsert(seat);

            }
        }

    }

}
