<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>账户充值</title>
</head>
<body>

<div>
    <img src="pictures/background.jpg" width="100%"/>
</div>

<%--充值信息填写--%>
<div style="left:10%;position: absolute;top: 40%;color: white;">
    <form action="/recharge" style="z-index: 1">
        <div style="position: center ;color: white">
            <table border="1" style="color: white">
                <tr>
                    <td>充值金额</td>
                    <td>充值码</td>
                </tr>
                <tr>
                    <td><input type="text" name="count" required></td>
                    <td><input type="text" name="code" required></td>
                </tr>
            </table>
            <hr>
            <input type="submit" value="提交">
            &nbsp&nbsp&nbsp&nbsp
            <input type="button" value="返回" onclick="window.location.href='/merchant.jsp'" style="color: darkolivegreen">
            <br><hr>

            <%
                if(request.getAttribute("state")=="yes3"){
                    out.println("充值成功");
                }else if(request.getAttribute("state")=="no5"){
                    out.println("验证码输入有误");
                }
            %>
        </div>
    </form>
</div>
</body>
</html>
