<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<html>
<head>
    <title>店铺商品添加</title>
</head>
<body>

<div>
    <img src="pictures/background.jpg" width="100%"/>
</div>

<%--填写修改后的商品信息--%>
<div style="left:10%;position: absolute;top: 40%;color: white;">
    <form action="/add_goods" style="z-index: 1">
        <div style="position: center ;color: white">
            <table border="1" style="color: white">
                <tr>
                    <td>名称</td>
                    <td>价格</td>
                    <td>简介</td>
                </tr>
                <tr>
                    <td><input type="text" name="name" required></td>
                    <td><input type="text" name="price" required placeholder="务必输入数字"></td>
                    <td><input type="text" name="described" required></td>
                </tr>
            </table>
            <hr>
            <input type="submit" value="添加">
            &nbsp&nbsp&nbsp&nbsp
            <input type="button" value="返回" onclick="window.location.href='/merchant.jsp'" style="color: darkolivegreen">
            <br><hr>

                <%
                if(request.getAttribute("state")=="yes"){
                    out.println("添加成功,等待管理员审批");
                }else if(request.getAttribute("state")=="no3"){
                    out.println("商品信息输入有误");
                }
            %>
        </div>
    </form>
</div>

<%--展示待审核的店铺信息--%>
<div style="right:10%;position: absolute;top: 35%;color: white;">
    <form action="/cancel_apply">
        <div style="color: white">
            <table border="1" style="color: white">
                <tr>
                    <td colspan="5" align="center"> 审核中待上架商品 </td>
                </tr>
                <tr>
                    <td> </td>
                    <td width="100">名称</td>
                    <td width="100">价格</td>
                    <td width="100">简介</td>
                    <td width="100">提交时间</td>
                </tr>
                <c:forEach items="${decision_goods}" var="object">
                    <tr>
                        <td>
                            <input type="checkbox" name="carts" value="${object.getCart_num()}">
                        </td>
                        <td>
                                ${object.getName()}
                        </td>
                        <td>
                                ${object.getPrice()}
                        </td>
                        <td>
                                ${object.getDescribed()}
                        </td>
                        <td>
                                ${object.getSubmit_time()}
                        </td>
                    </tr>
                </c:forEach>
            </table>
            <hr>
            <input type="submit" value="取消申请">
            &nbsp&nbsp&nbsp&nbsp
            <input type="button" value="刷新" onclick="window.location.href='/decision_goods_display'" style="color: darkolivegreen">
            <br><hr>

                <%
                if(request.getAttribute("state")=="no"){
                    out.println("移除成功");
                }else if(request.getAttribute("state")=="no0"){
                    out.println("未选择商品");
                }
            %>
        </div>
    </form>

</div>
</body>
</html>
