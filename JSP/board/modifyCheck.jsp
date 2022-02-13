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
		String bId = request.getParameter("bId");
		String bName = request.getParameter("bName");
		String bTitle = request.getParameter("bTitle");
		String bContent = request.getParameter("bContent");
		
		boardDAO dao = boardDAO.getInstance();
		
		int result = dao.modify(bId, bName, bTitle, bContent);
		if(result==1){
	%>
	<script>
		alert('글이 수정되었습니다.');
		window.location="contentView.jsp?bId=<%=bId%>";
	</script>
	<%
		}else{
	%>
	<script>
		alert('글이 수정되지 않았습니다.');
		window.location="modifyForm.jsp";
	</script>
	<%
		}
	%>
</body>
</html>