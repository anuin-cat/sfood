package com.socks.www.service.deal_message.connect;

import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_user;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/login")
public class login extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //标志
        //System.out.println("------login-----");

        //判断用户类型
        //如果是商家，则转发至login_merchant处
        if("merchant".equals(request.getParameter("user_type"))){
            request.getRequestDispatcher("login_merchant").forward(request,response);
        }
        //如果是管理员，则转发至login_root处
        else if("root".equals(request.getParameter("user_type"))){
            request.getRequestDispatcher("login_root").forward(request,response);
        }

        System.out.println(request.getParameter("user_type"));
        //得到账号密码
        Emp_user user = new Emp_user();
        if(request.getAttribute("state")=="yes0"){
            //如果是从注册页面转发过来，则直接获取信息
            user = (Emp_user) request.getSession().getAttribute("user");
        }else {
            //如果是从登录页面抓发过来，则创建新用户，获取表单信息
            user.setAccount(request.getParameter("account"));
            user.setPassword(request.getParameter("password"));
        }


        //System.out.println(user);
        //查询账号数据
        List<Emp_user> emp_users = dateBase.userToQuery("select * from user where account='"+user.getAccount()+"' and password='"+user.getPassword()+"'");

        //设置状态
        String state;

        //判断是否有此人数据
        if(emp_users.size()==0){
            //没有此人信息，直接返回主界面
            state = "0";
            request.setAttribute("state",state);
            request.getRequestDispatcher("main.jsp").forward(request,response);
        }else{
            //有此人信息，转发至商品加载页面
            state = "1";

            //存储信息
            request.setAttribute("state",state);
            request.getSession().setAttribute("ys_user",emp_users.get(0));

            //页面转发
            request.getRequestDispatcher("object_display").forward(request,response);
            System.out.println(emp_users.get(0));
        }

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
