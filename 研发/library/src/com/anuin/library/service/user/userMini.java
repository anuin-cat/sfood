package src.com.anuin.library.service.user;

import javafx.scene.control.Label;
import src.com.anuin.library.bean.EmpEvaluate;
import src.com.anuin.library.bean.EmpOrder0;
import src.com.anuin.library.bean.EmpSeat;
import src.com.anuin.library.bean.EmpUser;
import src.com.anuin.library.dao.base.easyDML;
import src.com.anuin.library.dao.base.easyObject;
import src.com.anuin.library.dao.base.easyQuery;
import src.com.anuin.library.entity.EntSeat;
import src.com.anuin.library.entity.EntUser;


import java.sql.Date;
import java.text.DecimalFormat;
import java.text.SimpleDateFormat;
import java.util.List;

public class userMini {


    //账号状态保存
    public static void storageState(EmpUser user){
        easyDML.userUpdate("id","1",Integer.class,"account",user.getAccount()+"",String.class);
    }

    //取出状态
    public static EmpUser getUsed(){
        List<EmpUser> users = easyQuery.easyUser("id", "1", Integer.class);
        List<EmpUser> users1 = easyQuery.easyUser("account", users.get(0).getAccount() + "", String.class);
        return users1.get(1);
    }

    //获取位置
    public static Label getLabel(String text){
        int X;
        int Y;
        int index = 0;
        String Xs = "";
        String Ys = "";

        for(int i=0;i<text.length();i++){
            if(text.charAt(i)==45){
                index = i;
                break;
            }
            if(text.charAt(i)>=48 && text.charAt(i)<=57){
                Xs+=text.charAt(i);
            }
        }
        for(int j=index+1;j<text.length();j++){
            if(text.charAt(j)>=48 && text.charAt(j)<=57){
                Ys+=text.charAt(j);
            }else {
                break;
            }
        }

        //存储座位信息到全局变量
        EmpSeat empSeat ;
        List<EmpSeat> empSeats = easyQuery.easySeat("Xposition", Integer.parseInt(Xs) + "", Integer.class, "Yposition", Integer.parseInt(Ys) + "", Integer.class, EntSeat.realFloor + "");
        if(empSeats!=null&&empSeats.size()>=1){
            empSeat = empSeats.get(0);
        }else {
            empSeat = new EmpSeat();
            empSeat.setType("禁用");
            empSeat.setSection(",");
            empSeat.setXposition(13);
            empSeat.setYposition(13);
            empSeat.setAppointment(6);
            empSeat.setCount(0);
            empSeat.setGrade(0);
            empSeat.setFloor(0);
            empSeat.setId(0);
        }
        userMini.EntStorage(empSeat);

        return EntSeat.Labelss.get(Integer.parseInt(Xs)).get(Integer.parseInt(Ys));
    }


    //全局存储
    public static void EntStorage(EmpSeat seat){
        EntSeat.id = seat.getId();
        EntSeat.Xposition = seat.getXposition();
        EntSeat.Yposition = seat.getYposition();
        EntSeat.type = seat.getType();
        EntSeat.section = seat.getSection();
        EntSeat.grade = seat.getGrade();
        EntSeat.count = seat.getCount();
        EntSeat.appointment = seat.getAppointment();
        EntSeat.floor = seat.getFloor();
    }

    //添加账号信息到数据库
    public static void storageUserChart(EmpUser user){
        user.setId(
                easyObject.max("user0","id")+1
        );
        user.setIdOrder(
                easyObject.max("user0","id_order")+1
        );
        user.setIdEvaluate(
                easyObject.max("user0","id_evaluate")+1
        );
        user.setIsBlack("NO");

        storageEntUser(user);

        easyDML.userInsert(user);
    }

    //添加账号信息到全局变量
    public static void storageEntUser(EmpUser user){
        EntUser.id = user.getId();
        EntUser.idEvaluate = user.getIdEvaluate();
        EntUser.isBlack = user.getIsBlack();
        EntUser.idOrder = user.getIdOrder();
        EntUser.password = user.getPassword();
        EntUser.account = user.getAccount();
    }

    //搜索字符串前几个数字
    public static String searchNum(String s){
        String temp = "";
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)>=48 && s.charAt(i)<=57){
                temp += s.charAt(i);
            }else {
                break;
            }
        }
        return temp;
    }

    //传入订单id评论评分，转化为评论存储
    public static void storageEvaluate(String id_order,String content,String grade){
        List<EmpOrder0> orders = easyQuery.easyOrder("id", id_order, Integer.class);
        if(orders!=null){
            EmpOrder0 order = orders.get(0);
            EmpEvaluate eva = new EmpEvaluate();
            Integer id = easyObject.max("evaluate", "id");
            if(id==0){
                id=0;
            }

            eva.setId(easyObject.max("evaluate","id")+1);
            eva.setContent(content);
            eva.setGrade(Integer.parseInt(grade));
            eva.setTime(new Date(System.currentTimeMillis()));
            eva.setIdUser(EntUser.id);
            eva.setIdSeat(order.getIdSeat());
            eva.setIdOrder0(Integer.parseInt(id_order));

            easyDML.evaluateInsert(eva);
        }

    }

    //计算图书馆总评得分
    public static String averageLibrary(){
        double average = 0;
        double i = 0;
        for(EmpSeat seat:easyQuery.easySeat()){
            average += seat.getGrade();
            i++;
        }
        return new DecimalFormat(".00").format((average+1.0)/i);
    }

    //计算各座位等级
    public static void averageSeat(){
        //初始化分数+份数数组
        int[] a = new int[1000];
        int[] b = new int[1000];
        for(int i=0;i<1000;i++){
            a[i]=8;
            b[i]=1;
        }

        //计算每一个座位的总得分与评论份数
        for(EmpEvaluate evaluate:easyQuery.easyEvaluate()){
            a[evaluate.getIdSeat()] += evaluate.getGrade();
            b[evaluate.getIdSeat()] += 1;
        }

        //遍历并赋值
        int i = 0;
        for(EmpSeat seat : easyQuery.easySeat()){
//            b[i] += seat.getCount();
//            a[i] += seat.getGrade()*seat.getCount();
            easyDML.seatUpdate("id",seat.getId()+"",Integer.class,
                    "grade",(a[i]/b[i])+"",Integer.class);
            easyDML.seatUpdate("id",seat.getId()+"",Integer.class,
                    "count",(b[i])+"",Integer.class);
            i++;
        }
    }
}
