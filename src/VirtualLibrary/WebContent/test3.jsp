<%@ page contentType="text/html;charset=gb2312" %>
<html>

<head>
    <title>��������ҳ�ϻ�����</title>
</head>

<body>
    <h3 align="center">��һ�� JSP ����ĵ�����ҳ��</h3>
    <p>���������߳������������ǣ�
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
        <br><a href="javascript:history.back()">����</a>&nbsp;
        <a href="javascript:parent.close()">�ر�</a>
    </p>
</body>

</html>