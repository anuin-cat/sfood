package src.com.anuin.library.view.aside;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import src.com.anuin.library.bean.EmpUser;
import src.com.anuin.library.service.connect.Register;
import src.com.anuin.library.service.user.userMini;
import src.com.anuin.library.view.Ent.EntView;
import src.com.anuin.library.view.Main;

public class registerWindow  {
    //工具人上线
    public static void start() {

        //创建注册的窗口部分
        EntView.EntRegister.setAlignment(Pos.CENTER);

        Label A = new Label("账号：");
        Label P = new Label("密码：");
        Label tip = new Label();

        tip.setTextFill(Color.GREEN);

        TextField account = new TextField();
        TextField password = new TextField();

        EntView.EntRegister.add(A,0,1);
        EntView.EntRegister.add(P,0,2);
        EntView.EntRegister.add(tip,1,4);
        EntView.EntRegister.add(account,1,1);
        EntView.EntRegister.add(password,1,2);

        //login.setGridLinesVisible(true);
        Button bt1 = new Button("返回");
        Button bt2 = new Button("注册");

        //返回事件
        bt1.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                EntView.EntRegisterStage.close();
                EntView.EntPrimaryStage.show();
            }
        });

        //注册事件
        bt2.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                EmpUser user = new EmpUser();

                user.setAccount(account.getText());
                user.setPassword(password.getText());

                String state = Register.checkAccount(user.getAccount());

                if(state.equals("YES")){
                    tip.setText("账号重复，请重新输入！");
                }else if(state.equals("NO")){
                    //处理账号生成问题
                    userMini.storageUserChart(user);
                    //存储账号状态
                    userMini.storageState(user);
                    tip.setText("注册成功！");
                }
            }
        });



        EntView.EntRegister.add(bt1,0,3);
        EntView.EntRegister.add(bt2,1,3);

        EntView.EntRegisterStage.setTitle("图书馆1");
        EntView.EntRegisterStage.setScene(new Scene(EntView.EntRegister,400,220));
        EntView.EntRegisterStage.show();
    }

}
