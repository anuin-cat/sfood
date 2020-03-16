<%@ page import="com.socks.www.service.java_code.create_random" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>账号注册</title>
</head>
<body>

<div>
    <img src="pictures/bj.png" width="100%" />
</div>

<div style="left: 35%;position: absolute;top: 35%;width: 50%;height: 50% " >
    <img src="pictures/background.jpg" width="55%" style="border: 3px solid #e1fa7f;"/>
</div>

<%--获取随机数--%>

<div style="left: 65%;position: absolute;top: 35%;color: black;">

    <form action="/register" method="post">
        <% String random = create_random.back_random(); session.setAttribute("random",random);%>

        昵称：<input type="text" name="userName"><br><br>
        账号：<input type="text" name="account"><br><br>
        密码：<input type="password" name="password1"><br>
        重复：<input type="password" name="password2"><br><br>
        验证码：<input type="text" name="random" size="10">
        <font style="border: 1px solid rgba(55,50,110,0.71);background: antiquewhite ; width: 150px" >
            <%= random %>
        </font>
        <br>
        <hr>
        &nbsp&nbsp&nbsp
        <input type="submit" value="   注册   ">
        &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
        <input type="button" value="返回登陆页面" onclick="window.location.href='/main.jsp'">
    </form>
    <%
        if(request.getAttribute("state")=="no0"){
            out.println("验证码输入错误");
            System.out.println("到达no0");
        }else if(request.getAttribute("state")=="no1") {
            out.println("账号已经存在");
            System.out.println("到达no1");
        }else if(request.getAttribute("state")=="no2") {
            out.println("两次密码输入不相同");
            System.out.println("到达no2");
        }else if(request.getAttribute("state")=="no3"){
            out.println("账号注册成功，请重新登录");
            System.out.println("到达no3");
        }
        System.out.println(request.getAttribute("state"));

    %>
</div>
</body>
</html>
