<%@ page import="com.socks.www.po.Emp_merchant" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>商家界面</title>
</head>
<body>
<div>
    <img src="pictures/background.jpg" width="100%"/>
</div>

<%--展示店铺的商品信息--%>
<div style="left:10%;position: absolute;top: 40%;color: white;">
    <form action="${pageContext.request.contextPath}/handle_merchant" style="z-index: 1">
        <div style="position: center ;color: white">
            <table border="1" style="color: white">
                <tr>
                    <td colspan="4" align="center"> 店铺商品 </td>
                </tr>
                <tr>
                    <td> </td>
                    <td width="100px">名称</td>
                    <td width="100px">价格</td>
                    <td width="200px">简介</td>
                </tr>
                <c:forEach items="${sessionScope.goods_pools}" var="goods">
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
                    </tr>
                </c:forEach>
            </table>
            <hr>
<%--            表单操作区域--%>
            <label>操作</label>
            <select name="operate" style="height: 26px">
                <option value="add">添加商品商品</option>
                <option value="delete">删除商品</option>
                <option value="change">修改商品信息(单个)</option>
            </select>
            &nbsp&nbsp&nbsp&nbsp
            <input type="submit" value="开始">
            &nbsp&nbsp&nbsp&nbsp
            <input type="button" value="刷新" onclick="window.location.href='/goods_pl_display'">
            <hr>
            <%
                if(request.getAttribute("state")=="add_yes"){
                    out.println("添加成功");
                }else if(request.getAttribute("state")=="yes2"){
                    out.println("商品信息修改成功");
                }else if(request.getAttribute("state")=="no1"){
                    out.println("未选择删除的商品");
                }else if(request.getAttribute("state")=="no4"){
                    out.println("未选择商品信息");
                }
            %>
        </div>
    </form>
</div>


<%--展示店家的个人信息--%>
<div style="right:10%;position: absolute;top: 40%;color: white;">
    <form action="${pageContext.request.contextPath}/change_name" style="z-index: 1">
        <div style="position: center ;color: white">
            <table border="1" style="color: white;border-color: dimgray">
                <tr>
                    <td colspan="3" align="center"> 商家信息 </td>
                </tr>
                <tr>
                    <td width="100px">昵称</td>
                    <td width="100px">账号</td>
                    <td width="100px">余额</td>
                </tr>
                <tr>
                    <% Emp_merchant ys_merchant = (Emp_merchant) request.getSession().getAttribute("ys_merchant"); %>
                    <td><%= ys_merchant.getName() %></td>
                    <td><%= ys_merchant.getAccount() %></td>
                    <td><%= ys_merchant.getBalance() %></td>
                </tr>
            </table>
            <hr>
            <%--            表单操作区域--%>
            <input type="submit" value="修改昵称">
            &nbsp&nbsp&nbsp
            <input type="button" value="账户充值" onclick="window.location.href='/merchant_recharge.jsp'">
            &nbsp&nbsp&nbsp
            <input type="button" value="重新登录" onclick="window.location.href='/main.jsp'">
            <hr>
            <%
                if(request.getAttribute("state")=="add_yes"){
                    out.println("添加成功");
                }
            %>
        </div>
    </form>
</div>
</body>
</html>
