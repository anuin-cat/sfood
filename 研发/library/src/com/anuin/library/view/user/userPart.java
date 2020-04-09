package src.com.anuin.library.view.user;

import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.paint.Color;
import src.com.anuin.library.bean.EmpEvaluate;
import src.com.anuin.library.bean.EmpOrder0;
import src.com.anuin.library.bean.EmpSeat;
import src.com.anuin.library.dao.base.easyDML;
import src.com.anuin.library.dao.base.easyObject;
import src.com.anuin.library.dao.base.easyQuery;
import src.com.anuin.library.entity.EntSeat;
import src.com.anuin.library.entity.EntUser;
import src.com.anuin.library.service.user.userCheck;
import src.com.anuin.library.view.Ent.EntView;

import java.sql.Date;
import java.time.LocalDate;
import java.util.List;


public class userPart {

    /**
     * 预约部分
     */

    //创建右上侧信息栏
    public static void seatMessage(){
        //创捷列表视图展示座位信息
        ObservableList<String> items = FXCollections.observableArrayList();
        EntView.EntList1.setItems(items);

        //向列表中添加信息
        items.add(0,"ID："+EntSeat.id);
        items.add(1,"Xposition："+EntSeat.Xposition);
        items.add(2,"Yposition："+EntSeat.Yposition);
        items.add(3,"所在楼层："+EntSeat.floor);
        items.add(4,"座位类型："+EntSeat.type);
        items.add(5,"评价等级："+EntSeat.grade);
        items.add(6,"评价人数："+EntSeat.count);
        items.add(7,"可提前预约的天数："+EntSeat.appointment);
        items.add(8,"每天可预约的时段："+EntSeat.section);

    }

    //创建右下侧预约栏
    public static void seatOrder(){
        //结点清空，重置
        EntView.EntOrder.getChildren().clear();
        EntView.extraInit();

        CheckBox choose;
        Label label;
        //获取日期
        LocalDate dateValue = EntView.EntDate.getValue();
        //更新日期
        userPart.updateBlack();
        //创建表格
        for(int i=0;i<4;i++){
            for(int j=0;j<6;j++){

                choose = new CheckBox((i*6+j+1)+"");
                label = new Label((i*6+j+1)+"");
                EntView.EntCheckBoxs.add((i*6+j),choose);

                //检查时间是否合法，设置颜色
                if(!userCheck.checkIsUsed((i*6+j+1)+"")||userCheck.checkIsTimeOrder((i*6+j+1)+"")||EntSeat.type.equals("禁用")||EntUser.isBlack.equals("YES")){
                    label.setTextFill(Color.RED);
                    EntView.EntOrder.add(label,i+1,j+1);
                }else {
                    choose.setTextFill(Color.GREEN);
                    EntView.EntOrder.add(choose,i+1,j+1);
                }
            }
        }


        //创建预约按钮
        EntView.EntBt1.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                int i=0;
                String s = ",";
                //测试时间查询
                userCheck.checkIsTimeOrder("1");
                //获取所有时间的集合
                for(CheckBox box:EntView.EntCheckBoxs){
                    if(box.isSelected()){
                        s += box.getText()+",";
                        box.getText();
                    }
                }
                //直接存储订单
                if(dateValue!=null&&(!s.equals(","))){
                    EmpOrder0 order = new EmpOrder0();
                    order.setTimeStart(Date.valueOf(dateValue));
                    order.setTime(s);
                    order.setIdUser(EntUser.id);
                    order.setIdSeat(EntSeat.id);
                    order.setId(easyObject.max("order0","id")+1);

                    easyDML.orderInsert(order);
                    EntView.EntTipOrder.setText("预约成功！");

                    EntView.EntCheckBoxs.clear();
                    userPart.seatOrder();
                }else{
                    EntView.EntTipOrder.setTextFill(Color.GREEN);
                    EntView.EntTipOrder.setText("预约失败！");

                    EntView.EntCheckBoxs.clear();
                    userPart.seatOrder();
                }
            }
        });
    }

    //创建右右下侧排序栏
    public static void updateGrade(){
        List<EmpSeat> seats = easyQuery.easySeat("floor", EntSeat.realFloor + "", Integer.class);
        //判断特殊情况
        if(seats==null||!(seats.size()>=1)){
            System.out.println("信息为空");
            return;
        }

        EntView.EntData.clear();
        int i=0;
        for(EmpSeat seat:seats){
            EntView.EntData.add(
                    i++,
                    new easySeat(
                            new SimpleStringProperty(seat.getXposition()+""),
                            new SimpleStringProperty(seat.getYposition()+""),
                            new SimpleStringProperty(seat.getGrade()+"")
                    )
            );
        }
        System.out.println(seats.get(1));
    }

    //创建右右上侧评价栏
    public static void updateEvaluate(){
        List<EmpEvaluate> evaluates = easyQuery.easyEvaluate("id_seat", EntSeat.id + "", String.class);
        EntView.EntItems.clear();
        for(EmpEvaluate evaluate:evaluates){
            EntView.EntItems.add(evaluate.getTime()+"："+evaluate.getContent()+"（等级："+evaluate.getGrade()+"）");
        }
    }

    //根据日期更新用户黑名单
    public static void updateBlack(){
        //当前
        long selectDay = EntView.EntDate.getValue().toEpochDay();

        //最小最大
        long now = LocalDate.now().toEpochDay();
        long end = now+EntSeat.appointment;


        if(now<=selectDay && end>=selectDay){
            EntUser.isBlack="NO";
        }else{
            EntUser.isBlack="YES";
        }

    }

    //转换时组件的更新
    public static void updateOrderPane(){
        //组件清除
        EntView.EntMainNode.getChildren().clear();
        EntView.EntMainNode.add(EntView.EntJump,0,0,1,2);

        //组件添加
        EntView.EntMainNode.add(EntView.EntTable,3,1);
        EntView.EntMainNode.add(EntView.EntList2,3,0);
        EntView.EntMainNode.add(EntView.EntCross,1,0,1,2);
        EntView.EntMainNode.add(EntView.EntList1,2,0);
        EntView.EntMainNode.add(EntView.EntOrder,2,1);
    }
    /**
     * 个人中心部分
     */

    //转换时组件的更新
    public static void updateSelfPane(){
        //卸载组件
        EntView.EntMainNode.getChildren().clear();
        EntView.EntMainNode.add(EntView.EntJump,0,0,1,2);
        //加载组件
        EntView.EntMainNode.add(EntView.EntList3,1,0);
        EntView.EntMainNode.add(EntView.EntList4,3,0);
        EntView.EntMainNode.add(EntView.EntList5,5,0);
        EntView.EntMainNode.add(EntView.EntMiniOrder,1,1);
        EntView.EntMainNode.add(EntView.EntMiniEvaluate1,3,1);
        EntView.EntMainNode.add(EntView.EntMiniEvaluate2,5,1);
        EntView.EntMainNode.add(EntView.EntLb31,2,0,1,2);
        EntView.EntMainNode.add(EntView.EntLb41,4,0,1,2);
        EntView.EntMainNode.add(EntView.Ent51,6,0,1,2);

//        EntView.EntMainNode.add();
    }
}
