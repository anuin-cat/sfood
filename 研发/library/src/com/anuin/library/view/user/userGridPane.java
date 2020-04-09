package src.com.anuin.library.view.user;

import javafx.event.EventHandler;
import javafx.event.EventTarget;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseButton;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import src.com.anuin.library.bean.EmpSeat;
import src.com.anuin.library.dao.base.easyQuery;
import src.com.anuin.library.entity.EntSeat;
import src.com.anuin.library.service.user.userMini;
import src.com.anuin.library.view.Ent.EntView;

import java.util.ArrayList;
import java.util.List;
import java.util.logging.Handler;

public class userGridPane {
    public static void cross(){
        //声明组件
        EmpSeat seat;
        List<EmpSeat> seats;
        Label miniSeat;

        EmpSeat redSeat=new EmpSeat();
        redSeat.setType("禁用");

        //清除集合信息
        for(int i=0;i<12;i++){
            EntSeat.Labelss.get(i).clear();
            EntSeat.seatss.get(i).clear();
        }

        //从数据库查询座位信息并填充集合
        for(int i=0;i<12;i++) {
            for(int j=0;j<12;j++){
                //数据库获取座位信息
                seats = easyQuery.easySeat(
                        "Xposition",i+"",Integer.class,
                        "Yposition",j+"",Integer.class,
                        EntSeat.realFloor+""
                );

                //设置座位标签
                miniSeat = new Label(i+"-"+j);
                miniSeat.setTextFill(Color.YELLOWGREEN);

                //判断是否存在座位
                if(seats!=null&&seats.size()>=1){
                    seat = seats.get(0);
                    //向静态集合中添加座位信息
                    EntSeat.seatss.get(i).add(j,seat);
                }else {
                    miniSeat = new Label("禁用");
                    miniSeat.setTextFill(Color.RED);
                    seat = redSeat;
                }


                //添加背景颜色
                if(seat.getType().equals("禁用")){
                    miniSeat.setBackground(new Background(new BackgroundFill(Color.RED,null,null)));
                }else {
                    miniSeat.setBackground(new Background(new BackgroundFill(Color.GREEN,null,null)));
                }

                //向静态集合中添加标签
                EntSeat.Labelss.get(i).add(j,miniSeat);
                //向表格中添加标签
                EntView.EntCross.add(EntSeat.Labelss.get(i).get(j),seat.getXposition(),seat.getYposition());

                //设置座位点击事件
                miniSeat.setOnMouseClicked(new EventHandler<MouseEvent>() {
                    @Override
                    public void handle(MouseEvent event) {
                        //存储标签，更新座位信息
                        String text = event.getTarget().toString();
                        userMini.getLabel(text);
                        userPart.seatMessage();
                        //刷新下侧候选栏
                        userPart.seatOrder();
                        //更新日期
                        userPart.updateBlack();
                        //更新评价
                        userPart.updateEvaluate();
                    }
                });

            }
        }

    }
}
