<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@ page import="java.sql.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<pre>

<% 
	String url = "jdbc:mysql://120.78.209.174:3306/vlibrary?user=onlooker&password=111&useSSL=false";
		String userName = "onlooker";
		String password = "111";
		Connection conn = null;		
		try {
			Class.forName("com.mysql.jdbc.Driver");
			} catch(ClassNotFoundException e) {
			
			out.println("loading class error");
		}
		try {
			conn = null;
			conn = DriverManager.getConnection(url);
		} catch(SQLException e) {
			out.println("sql exception");
		} if (conn==null)
			out.println("connect fail");
		else
			out.println("connect succeed");
		
        Statement stmt = conn.createStatement();
        ResultSet rs = stmt.executeQuery("select * from user");
    	out.println("\nid \t\t\t name");
        while(rs.next()){
            out.println("\n" + rs.getString("id")+ "\t\t\t" +rs.getString("username"));
        }
		
		
		try {
			conn.close();	
		} catch (SQLException e) {
			out.println("sql exception in closing db");
		} 
		%>
</pre>

</body>
</html>