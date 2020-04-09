package src.com.anuin.library.view.user;

import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import src.com.anuin.library.bean.EmpEvaluate;
import src.com.anuin.library.bean.EmpOrder0;
import src.com.anuin.library.dao.base.easyDML;
import src.com.anuin.library.dao.base.easyQuery;
import src.com.anuin.library.entity.EntUser;
import src.com.anuin.library.service.user.userMini;
import src.com.anuin.library.view.Ent.EntView;

import java.sql.Date;
import java.time.LocalDate;
import java.util.List;

public class userSelfWindow {
    public static void mainInit(){
        //自己的评价窗口初始化数据
        selfEvaluateInit();
        //两个预约窗口数据初始化
        selfOrderInit();
        //鼠标点击事件
        selfButtonInit();
    }

    //自己的评价窗口初始化数据
    private static void selfEvaluateInit(){
        List<EmpEvaluate> evaluates = easyQuery.easyEvaluate("id_user", EntUser.id + "", Integer.class);
        EntView.EntItems3.clear();
        for(EmpEvaluate evaluate:evaluates){
            EntView.EntItems3.add(evaluate.getId()+"  "+evaluate.getTime()+"："+evaluate.getContent()+"（等级："+evaluate.getGrade()+"）");
        }
    }

    //自己的历史he将来的预约窗口初始化数据
    private static void selfOrderInit(){
        //特殊情况判断
        List<EmpOrder0> orders = easyQuery.easyOrder("id_user", EntUser.id + "", Integer.class);
        if(orders==null||!(orders.size()>=1)){
            return;
        }
        //清空两个集合
        EntView.EntItems4.clear();
        EntView.EntItems5.clear();
        //获取当前日期
        long now = LocalDate.now().toEpochDay();
        //集合填充
        for(EmpOrder0 order:orders){
            if(order.getTimeStart().toLocalDate().toEpochDay()>now){
                EntView.EntItems5.add(order.getId()+"  日期："+order.getTimeStart()+"  时间点："+order.getTime());
            }else {
                EntView.EntItems4.add(order.getId()+"  日期："+order.getTimeStart()+"  时间点："+order.getTime());
            }
        }

    }


    //按钮事件
    private static void selfButtonInit(){
        //评论区取消评论
        EntView.EntBt31.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                String item = EntView.EntList3.getSelectionModel().getSelectedItem();
                if(item!=null){
                    easyDML.evaluateDelete("id", userMini.searchNum(item), Integer.class);
                }
                mainInit();
            }
        });
        //历史预约窗口评价
        EntView.EntBt41.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                String id = "";
                String content = "";
                String grade = "";
                String item = EntView.EntList4.getSelectionModel().getSelectedItem();
                if(item!=null){
                    id = userMini.searchNum(item);
                    content = EntView.EntTf41.getText();
                    grade = EntView.EntTf42.getText();
                    if(!(grade==null||grade.length()==0||userMini.searchNum(grade).length()==0)){
                        userMini.storageEvaluate(id,content,grade);
                    }
                }
                mainInit();
            }
        });
        //将来预约窗口取消预约
        EntView.EntBt42.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                String item = EntView.EntList5.getSelectionModel().getSelectedItem();
                String id_order = userMini.searchNum(item);
                easyDML.orderDelete("id",id_order,Integer.class);

                mainInit();
            }
        });
    }

}
