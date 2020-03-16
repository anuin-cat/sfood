<%@ page import="com.socks.www.po.Emp_object_pool" %>
<%@ page import="java.util.List" %>
<%@ page import="com.socks.www.po.Emp_user" %>
<%@ page import="com.socks.www.po.Emp_merchant" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>用户界面</title>
</head>
<body>
<div>
    <img style="z-index: -1" src="pictures/background.jpg" width="100%"/>
</div>


<%--全部店家商品展示--%>
<div style="left:10%;position: absolute;top: 35%;color: white;">
    <form action="goods_display">
    <%--            表单操作区域--%>
        <hr>
    <label>选择商家</label>

    <tr>
        <label>
            <select name="merchant_choice" style="height: 26px">
                <c:forEach items="${sessionScope.merchants}" var="merchant">
                    <option value="${merchant.getGoods_pool()}">${merchant.getName()}</option>
                </c:forEach>
            </select>
        </label>
        &nbsp&nbsp&nbsp&nbsp
        <input type="submit" value="查询">
    </tr>

    </form>

    <form action="/add_cart" style="z-index: 1">
    <div style="position: center ;color: white">
        <table border="1" style="color: white">
            <tr>
                <td> </td>
                <td width="100px">名称</td>
                <td width="100px">价格</td>
                <td width="200px">简介</td>
            </tr>
        <c:forEach items="${sessionScope.object_pool}" var="object">
            <tr>
                <td>
                    <input type="checkbox" name="carts" value="${object.getCart_num()}">
                </td>
                <td width="100px">
                        ${object.getName()}
                </td>
                <td width="100px">
                        ${object.getPrice()}
                </td>
                <td width="200px">
                        ${object.getDescribed()}
                </td>
            </tr>
        </c:forEach>
        </table>

        &nbsp&nbsp&nbsp&nbsp
        <input type="submit" value="加入购物车">
        &nbsp&nbsp&nbsp&nbsp
        <input type="button" value="刷新" onclick="window.location.href='/object_display'">
        <hr>
        <%
            if(request.getAttribute("state")=="add_yes"){
                out.println("添加成功");
            }else if(request.getAttribute("state")=="cart_repeat"){
                out.println("商品重复");
            }
        %>
    </div>
    </form>
</div>

<%--个人信息--%>
<div style="left:10%;position: absolute;top: 10%;color: white;">
    <form action="${pageContext.request.contextPath}/change_name0" style="z-index: 1">
        <div style="position: center ;color: white">
            <table border="1" style="color: white;border-color: dimgray">
                <tr>
                    <td colspan="3" align="center"> 个人信息 </td>
                </tr>
                <tr>
                    <td width="100px">昵称</td>
                    <td width="100px">账号</td>
                    <td width="100px">余额</td>
                </tr>
                <tr>
                    <% Emp_user ys_user = (Emp_user) request.getSession().getAttribute("ys_user"); %>
                    <td><%= ys_user.getName() %></td>
                    <td><%= ys_user.getAccount() %></td>
                    <td><%= ys_user.getBalance() %></td>
                </tr>
            </table>
            <hr>
            <%--            表单操作区域--%>
            <input type="submit" value="修改昵称">
            &nbsp&nbsp&nbsp
            <input type="button" value="充值" onclick="window.location.href='/user_recharge.jsp'">
            &nbsp&nbsp&nbsp
            <input type="button" value="重新登录" onclick="window.location.href='/main.jsp'">
            &nbsp&nbsp&nbsp
            <input type="button" value="成为商家" onclick="window.location.href='/become_merchant'">
            <hr>
            <%
                if(request.getAttribute("state")=="yes_4"){
                    out.println("修改成功");
                }else if(request.getAttribute("state")=="no5"){
                    out.println("验证码错误");
                }else if(request.getAttribute("state")=="yes3"){
                    out.println("充值成功");
                }else if(request.getAttribute("state")=="yes5"){
                    out.println("申请成功，请等待管理员批准");
                }
            %>
        </div>
    </form>
</div>

<%--个人购物车商品展示--%>
<div style="position: absolute;top: 40%;right: 10%;color: white;">
    <form action="/remove_cart">
        <div style="position: center ;color: white">
            <table border="1" style="color: white">
                <tr>
                    <td colspan="4" align="center"> 购物车 </td>
                </tr>
                <tr>
                    <td> </td>
                    <td width="100px">名称</td>
                    <td width="100px">价格</td>
                    <td width="100px">简介</td>
                </tr>
                <c:forEach items="${cart_pool}" var="object">
                    <tr>
                        <td>
                            <input type="checkbox" name="carts" value="${object.getCart_num()}">
                        </td>
                        <td width="100px">
                                ${object.getName()}
                        </td>
                        <td width="100px">
                                ${object.getPrice()}
                        </td>
                        <td width="100px">
                                ${object.getDescribed()}
                        </td>
                    </tr>
                </c:forEach>
            </table>
            <hr>
            &nbsp&nbsp&nbsp&nbsp&nbsp
            <input type="submit" value="移出购物车"/>
            &nbsp&nbsp&nbsp&nbsp&nbsp
            <input type="button" value="结算" onclick="window.location.href='/cart_end'"><br>
            <hr>
            <%
                if(request.getAttribute("state")=="yes0"){
                    out.println("移除成功");
                }else if(request.getAttribute("state")=="yes1"){
                    out.println("购买成功，等待发货");
                }else if(request.getAttribute("state")=="no1"){
                    out.println("余额不足");
                }
            %>
        </div>
    </form>
</div>

<%--申请成为商家--%>

</body>
</html>



