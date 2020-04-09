package src.com.anuin.library.view.user;

import javafx.application.Application;
import javafx.beans.property.SimpleStringProperty;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;
import src.com.anuin.library.service.user.userMini;
import src.com.anuin.library.view.Ent.EntView;

public class userWindow {

    public static void start(){

        //创建主节点mainNode
        GridPane mainNode = EntView.EntMainNode;

        //创建座位表格
        userGridPane.cross();

        //创建右上侧信息栏
        userPart.seatMessage();

        //创建右下侧座位预约信息栏
        userPart.seatOrder();

        //创建右右下侧排序栏
        userPart.updateGrade();


        EntView.EntUserStage.show();
    }
}
