<%@ page contentType="text/html;charset=gb2312" %>
<html>

<head>
    <title>第一个页面信息的处理</title>
    <meta http-equiv="Content-Type" content="text/html;
charset=gb2312">
</head>

<body>
    <h3 align="center">第一个 JSP 程序的第二个页面</h3>
    <p>从上一页得知，您喜欢的事物是：
        <%
String lks=request.getParameter("likething");
lks=new String(lks.getBytes("iso-8859-1"));
session.setAttribute("lks",lks);
//session.putValue("lks",lks);
out.print(lks);
%>
    </p>
    <p>要做点别的什么事情吗？</p>
    <p>在网页上画个空心菱形吧。</p>
    <form method="POST" action="test3.jsp">
        <p>请输入菱形的边长：<input type="text" name="side" size="6"></p>
        <p><input type="submit" value="提交" name="btn1"><input type="reset" value="重置" name="btn2"></p>
    </form>
    <p> </p>
</body>

</html>