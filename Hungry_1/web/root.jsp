<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>后台管理</title>
</head>
<body>
<div>
    <img src="pictures/background.jpg" width="100%"/>
</div>

<%--展示店铺的商品信息--%>
<div style="left:10%;position: absolute;top: 40%;color: white;">
    <form action="${pageContext.request.contextPath}/to_goods" style="z-index: 1">
        <div style="position: center ;color: white">
            <table border="1" style="color: white">
                <tr>
                    <td colspan="4" align="center"> 待审核上架商品 </td>
                </tr>
                <tr>
                    <td> </td>
                    <td width="100px">名称</td>
                    <td width="100px">价格</td>
                    <td width="200px">简介</td>
                    <td width="200px">提交时间</td>
                </tr>
                <c:forEach items="${sessionScope.decision_goods}" var="goods">
                    <tr>
                        <td>
                            <input type="checkbox" name="carts" value="${goods.cart_num}">
                        </td>
                        <td>
                                ${goods.name}
                        </td>
                        <td>
                                ${goods.price}
                        </td>
                        <td>
                                ${goods.described}
                        </td>
                        <td>
                                ${goods.submit_time}
                        </td>
                    </tr>
                </c:forEach>
            </table>
            <hr>
            <%--            表单操作区域--%>
            <label>操作</label>
            <select name="operate" style="height: 26px">
                <option value="yes">通过</option>
                <option value="no">驳回</option>
            </select>
            &nbsp&nbsp&nbsp&nbsp
            <input type="submit" value="提交">
            &nbsp&nbsp&nbsp&nbsp
            <input type="button" value="刷新" onclick="window.location.href='/decision_goods_display0'">
            &nbsp&nbsp&nbsp&nbsp
            <input type="button" value="重新登录" onclick="window.location.href='/main.jsp'">
            <hr>
            <%
                if(request.getAttribute("state")=="1"){
                    out.println("添加成功");
                }else if(request.getAttribute("state")=="0"){
                    out.println("拒绝成功");
                }
            %>
        </div>
    </form>
</div>

<%--展示用户的基本信息--%>
<div style="right:10%;position: absolute;top: 40%;color: white;">
    <form action="${pageContext.request.contextPath}/to_merchant" style="z-index: 1">
        <div style="position: center ;color: white">
            <table border="1" style="color: white">
                <tr>
                    <td colspan="4" align="center"> 用户转商家申请 </td>
                </tr>
                <tr>
                    <td> </td>
                    <td width="100px">账号</td>
                    <td width="100px">密码</td>
                    <td width="200px">提交时间</td>
                </tr>
                <c:forEach items="${sessionScope.decision_users}" var="user">
                    <tr>
                        <td>
                            <input type="checkbox" name="accounts" value="${user.account}">
                        </td>
                        <td>
                                ${user.account}
                        </td>
                        <td>
                                ${user.password}
                        </td>
                        <td>
                                ${user.submit_time}
                        </td>
                    </tr>
                </c:forEach>
            </table>
            <hr>
            <%--            表单操作区域--%>
            <label>操作</label>
            <select name="operate" style="height: 26px">
                <option value="yes">通过</option>
                <option value="no">驳回</option>
            </select>
            &nbsp&nbsp&nbsp&nbsp
            <input type="submit" value="提交">
            &nbsp&nbsp&nbsp&nbsp
            <input type="button" value="刷新" onclick="window.location.href='/decision_goods_display0'">
            <hr>
            <%
                if(request.getAttribute("state")=="3"){
                    out.println("添加成功");
                }else if(request.getAttribute("state")=="2"){
                    out.println("拒绝成功");
                }
            %>
        </div>
    </form>
</div>
</body>
</html>
