package src.com.anuin.library.view.administrator;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;
import src.com.anuin.library.view.Ent.EntAdm;

public class admWindow extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception {
        //数据初始化
        EntAdm.initialize();

        //


        EntAdm.EntMainAdmStage.show();
    }
}
