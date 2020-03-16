<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>用户修改昵称</title>
</head>
<body>

<div>
    <img src="pictures/background.jpg" width="100%"/>
</div>

<%--充值信息填写--%>
<div style="left:10%;position: absolute;top: 40%;color: white;">
    <form action="${pageContext.request.contextPath}/change_name0" style="z-index: 1">
        <div style="position: center ;color: white">
            <table border="1" style="color: white">
                <tr>
                    <td>新的昵称</td>
                </tr>
                <tr>
                    <td><input type="text" name="name" required></td>
                </tr>
            </table>
            <hr>
            <input type="submit" value="提交">
            &nbsp&nbsp&nbsp&nbsp
            <input type="button" value="返回" onclick="window.location.href='/user.jsp'" style="color: darkolivegreen">
            <br><hr>

            <%
                if(request.getAttribute("state")=="yes4"){
                    out.println("修改成功");
                }else if(request.getAttribute("state")=="no5"){
                    out.println("验证码输入有误");
                }
            %>
        </div>
    </form>
</div>
</body>
</html>
