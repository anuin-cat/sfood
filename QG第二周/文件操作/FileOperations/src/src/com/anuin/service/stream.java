package src.com.anuin.service;

import java.io.*;
import java.util.Scanner;

public class stream {
    public static int change(String src,String content,Integer line){

        String insertS = "D:\\niu.txt";
        File temp = new File(insertS);

        //创建临时文件
        if(!temp.exists()) {
            try {
                temp.createNewFile();
            } catch (IOException e) {
                System.out.println("创建备用文件失败！");
                e.printStackTrace();
                return 0;
            }
        }


//        //读取用户输入
//        System.out.print("请输入目录路径：");
//        Scanner in = new Scanner(System.in);
//        src = in.nextLine();

        //检查文件是否存在
        File myFilePath = new File(src);
        try {
            //检测目录，或者创建
            if (!myFilePath.exists()) {
                if(myFilePath.createNewFile()){
                    System.out.println("原目录不存在，新建目录成功");
                }else {
                    System.out.println("新建目录失败");
                }
            }
            if(myFilePath.exists()){
//                //获取行数
//                System.out.println("请输入需要更新的行数：");
//                while(true){
//                    if(in.hasNextInt()){
//                        line = in.nextInt();
//                        break;
//                    }else {
//                        System.out.println("输入的不是整数，请重新输入：");
//                    }
//                }
//                content = in.nextLine();


//                //获取内容
//                System.out.println("请输入需要更新的内容：");
//                while(true){
//                    if(in.hasNextLine()){
//                        content = in.nextLine();
//                        break;
//                    }else {
//                        System.out.println("输入错误，请重新输入：");
//                    }
//                }

                //获取指定编码的文件流
                BufferedReader read = new BufferedReader(new InputStreamReader(new FileInputStream(src),"GBK"));
                BufferedWriter insert = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(insertS),"GBK"));


                String s = "";
                int index = 0;

                //将源文件的内容转移至临时文件，搜索指定行数插入数据
                while (null != (s = read.readLine())) {
                    if (index == line-1) {
                        insert.write(content+"\n");
                    } else {
                        insert.write(s + "\n");
                    }
                    index++;
                }

                //当原有行数小于指定行数，在文末写入
                if (index < line) {
                    insert.flush();
                    insert.close();
                    insert = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(insertS,true),"GBK"));
                    insert.write(content+"\n");
                }

                //刷新并关闭文件
                insert.flush();
                insert.close();
                read.close();

                //角色反转
                BufferedReader insert1 = new BufferedReader(new InputStreamReader(new FileInputStream(insertS),"GBK"));
                BufferedWriter read1 = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(src),"GBK"));


                //临时文件内容复制
                while (null != (s = insert1.readLine())) {
                    read1.write(s + "\n");
                }


                //刷新关闭
                read1.flush();
                read1.close();
                insert1.close();

                //删除
                temp.delete();
                System.out.println("------------------------------------------------");

            }
        }
        catch (Exception e){
            System.out.println("新建文件出错");
            e.printStackTrace();
            return 0;
        }
        return 1;
    }
}
