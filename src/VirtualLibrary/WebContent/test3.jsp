<%@ page contentType="text/html;charset=gb2312" %>
<html>

<head>
    <title>试着在网页上画菱形</title>
</head>

<body>
    <h3 align="center">第一个 JSP 程序的第三个页面</h3>
    <p>按您给定边长画出的菱形是：
        <%
out.print("<br>");
int i,j,n=Integer.parseInt(request.getParameter("side"));
for(i=1;i<=n;i++)
{
for(j=n-i;j>0;j--)
out.print("&nbsp;");
out.print("*");
if(i!=1)
{
for(j=1;j<2*(i-1);j++)
out.print("&nbsp;");
out.print("*");
}
out.print("<br>");
}
for(i=1;i<n;i++)
{
for(j=i-1;j>=0;j--)
out.print("&nbsp;");
out.print("*");
if(i!=n-1)
{
for(j=2*(n-i)-3;j>0;j--)
out.print("&nbsp;");
out.print("*<br>");
}
}
%>
        <br><a href="javascript:history.back()">返回</a>&nbsp;
        <a href="javascript:parent.close()">关闭</a>
    </p>
</body>

</html>