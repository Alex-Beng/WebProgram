<%@ page contentType="text/html;charset=gb2312" %>
<html>

<head>
    <title>��һ��ҳ����Ϣ�Ĵ���</title>
    <meta http-equiv="Content-Type" content="text/html;
charset=gb2312">
</head>

<body>
    <h3 align="center">��һ�� JSP ����ĵڶ���ҳ��</h3>
    <p>����һҳ��֪����ϲ���������ǣ�
        <%
String lks=request.getParameter("likething");
lks=new String(lks.getBytes("iso-8859-1"));
session.setAttribute("lks",lks);
//session.putValue("lks",lks);
out.print(lks);
%>
    </p>
    <p>Ҫ������ʲô������</p>
    <p>����ҳ�ϻ����������ΰɡ�</p>
    <form method="POST" action="test3.jsp">
        <p>���������εı߳���<input type="text" name="side" size="6"></p>
        <p><input type="submit" value="�ύ" name="btn1"><input type="reset" value="����" name="btn2"></p>
    </form>
    <p> </p>
</body>

</html>