package src.com.anuin.service;

import src.com.anuin.bean.EmpInstruct;

import java.util.List;

public class main {
    public static void main(String[] args) {
        stream s = new stream();
//        s.change();
        List<EmpInstruct> instructs = dataBase.extract();
        for(EmpInstruct instruct:instructs){
            System.out.println(instruct);
        }
    }


}
