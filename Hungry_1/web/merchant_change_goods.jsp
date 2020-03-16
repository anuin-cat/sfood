<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>商品信息更改</title>
</head>
<body>
<div>
    <img src="pictures/background.jpg" width="100%"/>
</div>

<%--展示店铺的商品信息--%>
<div style="left:20%;position: absolute;top: 40%;color: white;">
    <form action="${pageContext.request.contextPath}/change_goods" style="z-index: 1">
        &nbsp&nbsp&nbsp&nbsp店铺商品<br><br>
        <div style="position: center ;color: white">
            <table border="1" style="color: white">
                <tr>
                    <td> </td>
                    <td>名称</td>
                    <td>价格</td>
                    <td>简介</td>
                </tr>
                <c:forEach items="${sessionScope.goods_pools}" var="goods">
                    <tr>
                        <td>
                            <input type="checkbox" name="carts" value="${goods.getCart_num()}">
                        </td>
                        <td>
                                ${goods.getName()}
                        </td>
                        <td>
                                ${goods.getPrice()}
                        </td>
                        <td>
                                ${goods.getDescribed()}
                        </td>
                    </tr>
                </c:forEach>
                <tr>
                    <td> </td>
                    <td><input type="text" name="name" required></td>
                    <td><input type="text" name="price" required></td>
                    <td><input type="text" name="described" required></td>
                </tr>
            </table>
            <hr>
            <input type="submit" value="修改">
            &nbsp&nbsp&nbsp
            <input type="button" value="返回" onclick="window.location.href='/merchant.jsp'">
            <br>
            <hr>
            <%
                if(request.getAttribute("state")=="yes"){
                    out.println("修改成功");
                }else if(request.getAttribute("state")=="no4"){
                    out.println("商品信息选择有误");
                }
            %>
        </div>
    </form>
</div>
</body>
</html>
