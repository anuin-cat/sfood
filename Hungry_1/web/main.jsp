<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>登录界面</title>
</head>
<body>

<div>
    <img src="pictures/background.jpg" width="100%"/>
</div>
<div style="left:60%;position: absolute;top: 40%;color: white;z-index: 2;font-size: 100%">
<form action="/login" method="post" >
    账号：<input type="text" name="account"><br>
    密码：<input type="password" name="password"><br><br>


<%--    <label>操作</label>--%>
    <select name="user_type" style="height: 26px">
        <option value="user">我是用户</option>
        <option value="merchant">我是商家</option>
        <option value="root">我是管理员</option>
    </select>

<%--    <input type="checkbox" name="user_type" value="merchant" >--%>
<%--    我是商家<br>--%>
<%--    <input type="checkbox" name="user_type" value="root" >--%>
<%--    我是管理员<br>--%>
<%--    <hr>--%>
    &nbsp&nbsp&nbsp
    <input type="submit" value="登录" style="color: darkolivegreen">
    &nbsp&nbsp&nbsp
    <input type="button" value="注册" onclick="window.location.href='/register.jsp'" style="color: darkolivegreen">
</form>

    <%
        String wri = " ";
        if(request.getAttribute("state")=="0"||request.getAttribute("state")=="2"||request.getAttribute("state")=="4"){
            wri = "账号或者密码错误";
        }else if (request.getAttribute("state")=="1"||request.getAttribute("state")=="3"||request.getAttribute("state")=="5"){
            wri = "登陆成功";
        }else {
            wri = " ";
        }

        //System.out.println(request.getAttribute("state"));
    %><br>
<%--    输出登录信息--%>
    <font size="2" color="#778899" face="verdana"><%= wri%></font>
<%--    登陆成功转跳--%>
    <%
        if (request.getAttribute("state") == "1") {
            request.getRequestDispatcher("/get_merchants").forward(request, response);
        }else if(request.getAttribute("state") == "3"){
            request.getRequestDispatcher("/goods_pl_display").forward(request, response);
        }else if(request.getAttribute("state") == "5"){
            request.getRequestDispatcher("/decision_goods_display0").forward(request, response);
        }
    %>
</div>

<%--</div>--%>
</body>
</html>
