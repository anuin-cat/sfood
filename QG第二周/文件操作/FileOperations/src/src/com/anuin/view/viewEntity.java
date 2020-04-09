package src.com.anuin.view;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.ListView;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;


import java.util.List;

public class viewEntity {
    //主舞台+主场景+主框架
    public static Stage primaryStage = new Stage();
    public static GridPane mainPane = new GridPane();
    public static Scene scene = new Scene(mainPane,650,300);

    //列表
    public static ListView<String> EmpList = new ListView<>();



    public static void init(){
        //主框架设置
        mainPane.setAlignment(Pos.CENTER);
        mainPane.setPadding(new Insets(20,20,20,20));
        mainPane.setHgap(20);
        mainPane.setVgap(20);



        //主窗口设置

        primaryStage.setScene(scene);
        primaryStage.setTitle("文件操作");

    }



}
