package src.com.anuin.library.entity;

import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Button;
import src.com.anuin.library.bean.EmpSeat;

import java.util.ArrayList;

public class EntSeat {
    public static Integer id;
    public static Integer Xposition;
    public static Integer Yposition;
    public static String type;
    public static String section;
    public static Integer grade;
    public static Integer count;
    public static Integer appointment = 7;
    public static Integer floor;

    public static Integer realFloor = 1;

    public static ArrayList<ArrayList<EmpSeat>> seatss;
    static {
        seatss = new ArrayList<ArrayList<EmpSeat>>();
        ArrayList<EmpSeat> seats;
        for(int i=0;i<12;i++){
            seats = new ArrayList<>();
            seatss.add(seats);
        }
    }

    public static ArrayList<ArrayList<Label>> Labelss;
    static {
        Labelss = new ArrayList<ArrayList<Label>>();
        ArrayList<Label> Labels;
        for(int i=0;i<12;i++){
            Labels = new ArrayList<>();
            Labelss.add(Labels);
        }
    }

    public static ArrayList<ArrayList<Button>> buttonss;
    static {
        buttonss = new ArrayList<ArrayList<Button>>();
        ArrayList<Button> buttons;
        for(int i=0;i<12;i++){
            buttons = new ArrayList<>();
            buttonss.add(buttons);
        }
    }
}
