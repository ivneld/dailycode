<%@page import="com.jsp.board.boardDAO"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
		request.setCharacterEncoding("UTF-8");
		String bName = request.getParameter("bName");
		String bTitle = request.getParameter("bTitle");
		String bContent = request.getParameter("bContent");
		
		boardDAO dao = boardDAO.getInstance();
		//getInstance메서드를 이용해 boardDAO 객체 생성
		
		int result = dao.write(bName,bTitle,bContent);
		if(result==1) {
	%>
	<script>
		alert('글이 등록되었습니다.');
		window.location = "boardList.jsp";
	</script>
	<%
		}else{
	%>
	<script>
		alert('글이 등록되지 않았습니다.');
		window.location = "writeForm.jsp";
	</script>
	<%
		}
	%>
</body>
</html>