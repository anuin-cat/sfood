package src.com.anuin.library.view.aside;

import javafx.geometry.Insets;
import javafx.scene.layout.GridPane;

public class widget {
    //创建标准表格
    public static GridPane standardGrid(){
        GridPane grid = new GridPane();
        grid.setVgap(5);
        grid.setHgap(5);
        grid.setPadding(new Insets(10,10,10,10));

        return grid;
    }

}
