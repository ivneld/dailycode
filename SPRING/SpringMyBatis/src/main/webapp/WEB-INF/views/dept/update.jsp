<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<div align="center">
		<form action="/db/update" method="post">
			<input type="hidden" value="${vo.deptno }" name="deptno">
			<table border="1">
				<tr>
					<th>Name</th>
					<td>
						<input type="text" name="dname" value="${vo.dname }">
					</td>
				</tr>
				<tr>
					<th>Loc</th>
					<td>
						<input type="text" name="loc" value="${vo.loc }">
					</td>
				</tr>
				<tr>
					<th align="right" colspan="2">
						<input type="submit" value="추가">
						<input type="button" value="리스트" onclick="location.href='/db/'">
					</th>
				</tr>
			</table>
		</form>
	</div>
</body>
</html>











