<%@ page language="java"
contentType="text/html;charset=gb2312"%>
<html>

<head>
    <title>��һ�� JSP ��ҳ</title>
</head>

<body>
    <h3 align="center">��һ�� JSP ��ҳ</h3>
    <p>������ʾ�ľ�̬����</p>
    <% out.println("���Ƕ�̬��ʾ������"); %>
    <form method="POST" action="test2.jsp">
        <p>��������ϲ�������</p>
        <p><input type="text" name="likething" size="20"></p>
        <p><input type="submit" value="�ύ" name="btn1"> <input type="reset" value="����" name="btn2"></p>
    </form>
</body>

</html>