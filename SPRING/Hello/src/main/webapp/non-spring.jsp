<%@page import="vo.personVO"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%
	//기존방식
	personVO p1 = new personVO();
	p1.setName("김민준");
	p1.setAge(20);
	p1.setTel("010-3666-6768");
 
	personVO p2 = new personVO("홍길동",20,"010-0000-1111");
	
	pageContext.setAttribute("p1", p1);
	request.setAttribute("p2", p2);
	
%>
    
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<div align="center">
		${p1.name } / ${p1.age } /${p1.tel }<br>
		${p2.name } / ${p2.age } /${p2.tel }<br>
	</div>
</body>
</html>


















