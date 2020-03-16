package com.socks.www.service.deal_message.root;

import com.socks.www.dao.base.add;
import com.socks.www.dao.base.delete;
import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_decision_pool_user;
import com.socks.www.po.Emp_merchant;
import com.socks.www.po.Emp_user;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/to_merchant")
public class to_merchant extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //标识
        System.out.println("-----to_merchant-----");

        //获取审核通过的用户账号
        String[] accounts = request.getParameterValues("accounts");

        //判断类型并处理
        if("yes".equals(request.getParameter("operate"))){
            //审核通过，开始转移数据

            //逐个添加商家并删除用户
            for(String account : accounts){
                //获取用户全部信息至Emp_user类
                List<Emp_user> users = dateBase.userToQuery("select * from user where account=" + account);

                //在商家库中添加相应的用户
                add.addMerchant(users.get(0));

                //将用户库 和 决策库 中的数据删除
                delete.removeUser(account);
                delete.removeDecisionUser(account);
            }

            //设置状态，
            request.setAttribute("state","3");

            //刷新并返回root界面
            request.getRequestDispatcher("decision_goods_display0").forward(request,response);
        }

        if("no".equals(request.getParameter("operate"))){
            //审核不通过，删除并驳回
            for(String account : accounts){
                //决策库 中的数据删除
                delete.removeDecisionUser(account);
            }

            //设置状态，
            request.setAttribute("state","2");

            //刷新并返回root界面
            request.getRequestDispatcher("decision_goods_display0").forward(request,response);
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
