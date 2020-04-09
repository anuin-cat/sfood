package src.com.anuin.library.view.user;

import javafx.beans.property.SimpleStringProperty;

public class easySeat {
    private final SimpleStringProperty x;
    private final SimpleStringProperty y;
    private final SimpleStringProperty grade;


    public easySeat(SimpleStringProperty x, SimpleStringProperty y, SimpleStringProperty grade) {
        this.x = x;
        this.y = y;
        this.grade = grade;
    }

    public String getX() {
        return x.get();
    }

    public SimpleStringProperty xProperty() {
        return x;
    }

    public void setX(String x) {
        this.x.set(x);
    }

    public String getY() {
        return y.get();
    }

    public SimpleStringProperty yProperty() {
        return y;
    }

    public void setY(String y) {
        this.y.set(y);
    }

    public String getGrade() {
        return grade.get();
    }

    public SimpleStringProperty gradeProperty() {
        return grade;
    }

    public void setGrade(String grade) {
        this.grade.set(grade);
    }

    @Override
    public String toString() {
        return "easySeat{" +
                "x=" + x +
                ", y=" + y +
                ", grade=" + grade +
                '}';
    }
}
