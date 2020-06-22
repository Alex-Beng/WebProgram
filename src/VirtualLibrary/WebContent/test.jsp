<%@ page language="java"
contentType="text/html;charset=gb2312"%>
<html>

<head>
    <title>第一个 JSP 网页</title>
</head>

<body>
    <h3 align="center">第一个 JSP 网页</h3>
    <p>这是显示的静态内容</p>
    <% out.println("这是动态显示的内容"); %>
    <form method="POST" action="test2.jsp">
        <p>请输入您喜欢的事物：</p>
        <p><input type="text" name="likething" size="20"></p>
        <p><input type="submit" value="提交" name="btn1"> <input type="reset" value="重置" name="btn2"></p>
    </form>
</body>

</html>