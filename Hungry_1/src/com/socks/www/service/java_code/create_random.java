package com.socks.www.service.java_code;

public class create_random {
    static String str = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm0123456789";

    public static String back_random(){
        String random = "";
        for (int i=0;i<4;i++){
            random += str.charAt((int) (Math.random()*61));
        }
        return random;
    }

}
