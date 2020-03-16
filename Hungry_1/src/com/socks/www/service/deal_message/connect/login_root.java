package com.socks.www.service.deal_message.connect;

import com.socks.www.dao.dateBase;
import com.socks.www.po.Emp_merchant;
import com.socks.www.po.Emp_root;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/login_root")
public class login_root extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //得到账号密码+存储商家账户信息
        Emp_root root = new Emp_root();
        root.setAccount(request.getParameter("account"));
        root.setPassword(request.getParameter("password"));

        //查询账号数据
        List<Emp_root> roots = dateBase.rootToQuery(
                "select * from root where account='" + root.getAccount() + "' and password='" + root.getPassword() + "'"
        );

        String state;

        //判断是否有此人数据
        if(roots.size()==0){
            state = "4";    //没有
        }else{
            state = "5";    //有
            //存储管理员信息
            request.getSession().setAttribute("ys_root",roots.get(0));
            //System.out.println("-----login_merchant-----");
            //System.out.println(merchants.get(0));
        }


        //储存判断信息
        request.setAttribute("state",state);
        request.getRequestDispatcher("main.jsp").forward(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
