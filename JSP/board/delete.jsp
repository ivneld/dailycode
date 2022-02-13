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
		String bId = request.getParameter("bId");
		boardDAO dao = boardDAO.getInstance();
		
		int result = dao.delete(bId);
		if(result==1){
	%>
	<script>
		alert('글이 삭제되었습니다.');
		window.location = "boardList.jsp";
	</script>
	<%
		}else{
	%>
	<script>
		alert('글이 삭제되지 않았습니다.');
		window.location = "boardList.jsp";
	</script>
	<%
		}
	%>
</body>
</html>