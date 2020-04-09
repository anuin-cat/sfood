package src.com.anuin.view;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Separator;
import javafx.scene.control.TextField;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import src.com.anuin.bean.EmpInstruct;
import src.com.anuin.dao.base.database;
import src.com.anuin.service.dataBase;
import src.com.anuin.service.stream;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

public class main extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception {
        viewEntity.init();

        //输入域
        TextField src = new TextField("D:\\s.txt");
        TextField row = new TextField("1");
        TextField content = new TextField("吃饱就溜");

        //提示域
        Label M = new Label("目录：");
        Label H = new Label("行数：");
        Label N = new Label("内容：");
        Label tip = new Label();

        //列表添加
        ObservableList<String> items = FXCollections.observableArrayList();
        List<EmpInstruct> instructs = dataBase.extract();
        int i=0;
        for(EmpInstruct instruct:instructs){
            if((i++)%3==0){
                items.add("#---"+instruct.getTime()+"---#");
            }
            items.add(instruct.getContent());
        }

        //按钮
        Button bt1 = new Button("开始");

        //属性设置
        tip.setTextFill(Color.GREEN);
        bt1.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                int state = stream.change(src.getText(), content.getText(), Integer.valueOf(row.getText()));

                if(state == 0){
                    tip.setText("运行失败！");
                }else {
                    dataBase.save(src.getText());
                    dataBase.save(row.getText());
                    dataBase.save(content.getText());
                    items.add("#----"+
                            (new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date()))+
                            "----#");
                    items.add(src.getText());
                    items.add(row.getText());
                    items.add(content.getText());
                    tip.setText("运行成功！");
                }
            }
        });

        //组件添加
        viewEntity.mainPane.add(M,0,0);
        viewEntity.mainPane.add(H,0,1);
        viewEntity.mainPane.add(N,0,2);
        viewEntity.mainPane.add(src,1,0);
        viewEntity.mainPane.add(row,1,1);
        viewEntity.mainPane.add(content,1,2);
        viewEntity.mainPane.add(bt1,0,3);
        viewEntity.mainPane.add(tip,0,4,2,1);

        viewEntity.EmpList.setItems(items);
        viewEntity.mainPane.add(viewEntity.EmpList,2,0,1,5);


        viewEntity.primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
