package src.com.anuin.library.view;

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
import src.com.anuin.library.dao.base.easyQuery;
import src.com.anuin.library.service.connect.Login;
import src.com.anuin.library.service.user.userMini;
import src.com.anuin.library.view.Ent.EntView;
import src.com.anuin.library.view.administrator.admWindow;
import src.com.anuin.library.view.aside.registerWindow;
import src.com.anuin.library.view.aside.widget;
import src.com.anuin.library.view.user.userWindow;

import java.util.List;

public class Main extends Application {

    //工具人上线
    @Override
    public void start(Stage primaryStage) throws Exception{
        //部分数据初始化
        EntView.initialize();
        EntView.MouseClick();
        registerWindow.start();
        userWindow.start();
//        userMini.averageSeat();
        EntView.EntGrade.setText("图书馆\n总评\n"+userMini.averageLibrary());
        EntView.EntRegisterStage.close();
        EntView.EntUserStage.close();

        //创建登录的窗口部分
        GridPane login = widget.standardGrid();
        login.setAlignment(Pos.CENTER);

        //获取登录状态
        EmpUser usedUser = userMini.getUsed();

        TextField account = new TextField(usedUser.getAccount());
        TextField password = new TextField(usedUser.getPassword());

        Label A = new Label("账号：");
        Label P = new Label("密码：");
        Label tip = new Label();
        tip.setTextFill(Color.GREEN);

        login.add(A,0,1);
        login.add(P,0,2);
        login.add(tip,1,4);
        login.add(account,1,1);
        login.add(password,1,2);

        //login.setGridLinesVisible(true);
        Button bt1 = new Button("登录");
        Button bt2 = new Button("注册");

        //登录事件
        bt1.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                EmpUser user = new EmpUser();

                user.setAccount(account.getText());
                user.setPassword(password.getText());

                String state = Login.login(user);

                if(state == "user"){
                    tip.setText("用户登陆成功！");
                    //记住登录状态
                    userMini.storageState(user);
                    //全局存储
                    EmpUser users = easyQuery.easyUser("account", user.getAccount(), String.class).get(1);
                    userMini.storageEntUser(users);
                    //主界面关闭
                    EntView.EntPrimaryStage.close();
                    //用户界面跳转
                    EntView.EntUserStage.show();


                }else if(state == "root"){
                    tip.setText("管理员登陆成功！");
                    //记住登录状态
                    userMini.storageState(user);
                    //管理员界面跳转
                    admWindow admWindow = new admWindow();
                    try {
                        admWindow.start(new Stage());
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    //主界面关闭
                    EntView.EntPrimaryStage.close();
                }else {
                    tip.setText("账号或密码错误！");
                }
            }
        });

        //注册事件
        bt2.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {

                EntView.EntPrimaryStage.close();
                EntView.EntRegisterStage.show();
            }
        });

        login.add(bt1,0,3);
        login.add(bt2,1,3);

        EntView.EntPrimaryStage.setTitle("图书馆1");
        EntView.EntPrimaryStage.setScene(new Scene(login,400,220));
        EntView.EntPrimaryStage.show();

    }

    public static void main(String[] args) {
        launch(args);
    }

}
