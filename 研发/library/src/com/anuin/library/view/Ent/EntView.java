package src.com.anuin.library.view.Ent;

import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Orientation;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import src.com.anuin.library.entity.EntSeat;
import src.com.anuin.library.service.user.userMini;
import src.com.anuin.library.view.aside.widget;
import src.com.anuin.library.view.user.easySeat;
import src.com.anuin.library.view.user.userGridPane;
import src.com.anuin.library.view.user.userPart;
import src.com.anuin.library.view.user.userSelfWindow;

import java.time.LocalDate;
import java.util.ArrayList;


public class EntView {
    /**
     *  User部分
     */
    //主舞台
    public static Stage EntPrimaryStage = new Stage();
    public static Scene EntMainScene;
    //用户主舞台
    public static Stage EntUserStage = new Stage();

    //主节点
    public static GridPane EntMainNode = new GridPane();

    //左左侧跳转栏
    public static GridPane EntJump = new GridPane();
    public static Label EntGrade= new Label();
    public static Button EntMainBt1 = new Button("预\n约\n座\n位");
    public static Button EntMainBt2 = new Button("个\n人\n中\n心");
    public static Separator EntSeparatorV = new Separator();

    //右右上侧评价栏
    public static ListView<String> EntList2 = new ListView<>();
    public static ObservableList<String> EntItems = FXCollections.observableArrayList();

    //右右下侧排序栏
    public static TableView<easySeat> EntTable = new TableView<>();
    public static ObservableList<easySeat> EntData = FXCollections.observableArrayList();


    //左侧座位表格
    public static GridPane EntCross = new GridPane();

    //右上座位信息
    public static ListView<String> EntList1 = new ListView<>();
    //右下预约部分
    public static GridPane EntOrder = new GridPane();
    public static DatePicker EntDate = new DatePicker();
    public static Label EntDateTip = new Label("预约日期:");
    public static Label EntTipOrder = new Label();
    public static Button EntBt1 = new Button("提交");
    public static ArrayList<CheckBox> EntCheckBoxs = new ArrayList<CheckBox>();
    public static final ChoiceBox EntCb = new ChoiceBox(FXCollections.observableArrayList(
            "1楼","2楼","3楼","4楼","5楼","6楼"
    ));


    //public static ListView<String> EmpList2 = new ListView<>();


    /**
     * 注册部分
     */
    public static Stage EntRegisterStage = new Stage();
    public static GridPane EntRegister;


    /**
     * 用户个人中心部分
     */
    //评论窗口
    public static Label EntLb31 = new Label("<-\n个\n人\n历\n史\n评\n论");
    public static GridPane EntMiniOrder = new GridPane();
    public static ListView<String> EntList3 = new ListView<>();
    public static ObservableList<String> EntItems3 = FXCollections.observableArrayList();
    public static Button EntBt31 = new Button("取消评论");

    //查看历史预约窗口
    public static Label EntLb41 = new Label("<-\n个\n人\n历\n史\n预\n约");
    public static GridPane EntMiniEvaluate1 = new GridPane();
    public static ListView<String> EntList4 = new ListView<>();
    public static ObservableList<String> EntItems4 = FXCollections.observableArrayList();

    public static Label EntLb42 = new Label("评价");
    public static Label EntLb43 = new Label("评分");
    public static TextField EntTf41 = new TextField();
    public static TextField EntTf42 = new TextField();
    public static Button EntBt41 = new Button("提交");
    public static Label EntTipOrder4 = new Label();

    //查看将来预约窗口
    public static Label Ent51 = new Label("<-\n个\n人\n将\n来\n预\n约");
    public static GridPane EntMiniEvaluate2 = new GridPane();
    public static ListView<String> EntList5 = new ListView<>();
    public static ObservableList<String> EntItems5 = FXCollections.observableArrayList();
    public static Button EntBt42 = new Button("取消预约");



    public static void initialize() {
        /**
         * 用户界面部分
         */
        //主节点
        EntMainNode.setAlignment(Pos.CENTER_LEFT);

        //左左侧跳转栏
        EntJump.setPadding(new Insets(0,0,0,0));
        EntJump.setVgap(50);
        EntJump.setAlignment(Pos.CENTER_LEFT);
        EntMainBt1.setAlignment(Pos.CENTER_LEFT);
        EntMainBt2.setAlignment(Pos.CENTER_LEFT);
        EntSeparatorV.setOrientation(Orientation.VERTICAL);
        EntJump.add(EntGrade,0,2);
        EntJump.add(EntMainBt1,0,0);
        EntJump.add(EntMainBt2,0,1);
        EntJump.add(EntSeparatorV,1,0,1,2);

        //右右上侧评价栏
        EntList2.setItems(EntItems);
        EntList2.setMaxHeight(250);

        //右右下侧排序栏
        EntTable.setMaxHeight(250);
        EntTable.setItems(EntData);
        EntTable.setEditable(true);
        TableColumn X = new TableColumn("X");
        X.setMinWidth(80);
        X.setCellValueFactory(
                new PropertyValueFactory<>("x")
        );
        TableColumn Y = new TableColumn("Y");
        Y.setMinWidth(80);
        Y.setCellValueFactory(
                new PropertyValueFactory<>("y")
        );
        TableColumn grade = new TableColumn("Grade");
        grade.setMinWidth(80);
        grade.setCellValueFactory(
                new PropertyValueFactory<>("grade")
        );
        EntTable.getColumns().addAll(X,Y,grade);


        //左侧列表栏
        EntCross.setAlignment(Pos.CENTER_LEFT);
        EntCross.setVgap(20);
        EntCross.setHgap(10);
        EntCross.setPadding(new Insets(20,10,20,10));

        //右上侧信息栏
        EntList1.setPrefSize(200,300);
        EntList1.setMaxHeight(250);

        //右下预约栏
        EntOrder.setVgap(3);
        EntOrder.setHgap(3);
        EntCb.setValue("1楼");
        EntDate.setValue(LocalDate.now());
        EntOrder.setPadding(new Insets(20,0,5,0));
        EntOrder.add(EntDate,1,0,4,1);
        EntOrder.add(EntTipOrder,1,7,4,1);
        EntOrder.add(EntBt1,0,7);
        EntOrder.add(EntCb,0,0);

        //结点添加
        //创建主窗口
        EntMainScene = new Scene(EntMainNode,1200,625);
        EntUserStage.setScene(EntMainScene);
        EntUserStage.setTitle("图书馆座位预约系统");
        EntMainNode.setVgap(10);
        EntMainNode.setHgap(10);
        EntMainNode.setPadding(new Insets(20,10,20,10));
        EntMainNode.add(EntTable,3,1);
        EntMainNode.add(EntList2,3,0);
        EntMainNode.add(EntCross,1,0,1,2);
        EntMainNode.add(EntList1,2,0);
        EntMainNode.add(EntOrder,2,1);
//        EntMainNode.getChildren().remove()
        EntMainNode.add(EntJump,0,0,1,2);


        /**
         * 注册部分
         */
        EntRegister = widget.standardGrid();

        /**
         * 用户个人中心部分
         */
        //评论窗口
        EntLb31.setTextFill(Color.GREEN);
        EntList3.setItems(EntItems3);
        EntList3.setMinWidth(335);
        EntMiniOrder.setVgap(20);
        EntMiniOrder.setHgap(20);
        EntMiniOrder.setPadding(new Insets(20,20,20,20));
        EntMiniOrder.add(EntBt31,0,0);

        //历史预约窗口
        EntLb41.setTextFill(Color.GREEN);
        EntList4.setItems(EntItems4);
        EntList4.setMinWidth(335);
        EntTipOrder4.setTextFill(Color.GREEN);
        EntMiniEvaluate1.setHgap(20);
        EntMiniEvaluate1.setVgap(20);
        EntMiniEvaluate1.setPadding(new Insets(20,20,20,20));

        EntMiniEvaluate1.add(EntBt41,0,2);
        EntMiniEvaluate1.add(EntLb42,0,0);
        EntMiniEvaluate1.add(EntLb43,0,1);
        EntMiniEvaluate1.add(EntTf41,1,0);
        EntMiniEvaluate1.add(EntTf42,1,1);
        EntMiniEvaluate1.add(EntTipOrder4,0,3,2,1);


        //将来预约窗口
        Ent51.setTextFill(Color.GREEN);
        EntList5.setItems(EntItems5);
        EntList5.setMinWidth(335);
        EntMiniEvaluate2.setHgap(20);
        EntMiniEvaluate2.setVgap(20);
        EntMiniEvaluate2.setPadding(new Insets(20,20,20,20));
        EntMiniEvaluate2.add(EntBt42,0,0);
    }

    //鼠标事件
    public static void MouseClick(){
        /**
         * user部分
         */

        EntDate.setOnKeyPressed(new EventHandler<KeyEvent>() {
            @Override
            public void handle(KeyEvent event) {
                if(event.getCode().getName().equals("ENTER")){
                    userPart.seatOrder();
                }
            }
        });

        EntCb.getSelectionModel().selectedIndexProperty().addListener(
                (ObservableValue<? extends Number> ov,
                Number old_val,Number new_val)->{
                    EntSeat.realFloor=new_val.intValue()+1;
                    userGridPane.cross();
                    userPart.updateGrade();
                }
        );

        //左左侧按钮事件
        EntMainBt1.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                userPart.updateOrderPane();
                userMini.averageSeat();
                EntGrade.setText("图书馆\n总评\n"+userMini.averageLibrary());
            }
        });

        EntMainBt2.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                userPart.updateSelfPane();
                userSelfWindow.mainInit();
                userSelfWindow.mainInit();
            }
        });
    }

    //小众初始化
    public static void extraInit(){
        EntOrder.add(EntDate,1,0,4,1);
        //EntOrder.add(EntDateTip,0,0);
        EntOrder.add(EntTipOrder,1,7,4,1);
        EntOrder.add(EntBt1,0,7);
        EntOrder.add(EntCb,0,0);
    }

}
