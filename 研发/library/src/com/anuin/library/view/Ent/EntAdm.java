package src.com.anuin.library.view.Ent;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;


public class EntAdm {
    /**
     * 定义
     */
    //主舞台
    public static Stage EntMainAdmStage = new Stage();
    public static Scene EntMainAdmScene;

    //主节点
    public static GridPane EntMainNode = new GridPane();

    //左上结点--拉黑用户
    public static GridPane EntNode1 = new GridPane();
    public static Label EntLb11 = new Label("账号：");
    public static TextField EntTf11= new TextField();
    public static Button EntBt11 = new Button("拉黑");

    //左下结点--设置提前预约时间
    public static GridPane EntNode2 = new GridPane();
    public static Label EntLb21 = new Label("座位ID：");
    public static Label EntLb22 = new Label("提前天：");
    public static TextField EntTf21= new TextField();
    public static TextField EntTf22= new TextField();
    public static Button EntBt21 = new Button("设置");

    //中上结点--设置可预约的时间段
    public static GridPane EntNode3 = new GridPane();
    public static Label EntLb31 = new Label("座位ID：");
    public static Label EntLb32 = new Label("预约时间：");
    public static Label EntLb33 = new Label("输入*表示设置全部座位的预约时间");
    public static TextField EntTf31= new TextField();
    public static TextField EntTf32= new TextField();
    public static Button EntBt31 = new Button("设置");

    //中下结点--上传图片
    public static GridPane EntNode4 = new GridPane();
    public static Label EntLb41 = new Label("座位ID：");
    public static Label EntLb42 = new Label("选择图片：");
    public static TextField EntTf41= new TextField();
    public static Button EntBt41 = new Button("上传");

    /**
     * 后期属性初始化
     */
    public static void initialize(){
        //主舞台
        EntMainAdmStage.setTitle("管理员窗口");
        EntMainAdmScene = new Scene(EntMainNode,1200,625);
        EntMainAdmStage.setScene(EntMainAdmScene);

        //主节点
        EntMainNode.setAlignment(Pos.CENTER);
        EntMainNode.setHgap(20);
        EntMainNode.setVgap(20);
        EntMainNode.setPadding(new Insets(20,10,20,10));
        EntMainNode.add(EntNode1,0,0);
        EntMainNode.add(EntNode2,0,1);
        EntMainNode.add(EntNode3,1,0);
        EntMainNode.add(EntNode4,1,1);

        //左上结点--拉黑用户
        EntNode1.setVgap(10);
        EntNode1.setHgap(10);
        EntNode1.setPadding(new Insets(20,20,20,20));
        EntNode1.add(EntLb11,0,0);
        EntNode1.add(EntTf11,1,0);
        EntNode1.add(EntBt11,0,1);

        //左下结点--提前预约
        EntNode2.setVgap(10);
        EntNode2.setHgap(10);
        EntNode2.setPadding(new Insets(20,20,20,20));
        EntNode2.add(EntLb21,0,0);
        EntNode2.add(EntTf21,1,0);
        EntNode2.add(EntLb22,0,1);
        EntNode2.add(EntTf22,1,1);
        EntNode2.add(EntBt21,0,2);

        //中上结点--设置可预约时间段
        EntNode3.setVgap(10);
        EntNode3.setHgap(10);
        EntNode3.setPadding(new Insets(20,20,20,20));
        EntNode3.add(EntLb33,0,0,2,1);
        EntNode3.add(EntLb31,0,1);
        EntNode3.add(EntTf31,1,1);
        EntNode3.add(EntLb32,0,2);
        EntNode3.add(EntTf32,1,2);
        EntNode3.add(EntBt31,0,3);

        //中下结点--上传图片

    }

    //事件初始化
    public static void eventClickInit(){
        

    }
}
