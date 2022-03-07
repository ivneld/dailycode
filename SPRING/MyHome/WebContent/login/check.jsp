<%@page import="member.MemberDAO"%>
<%@page import="member.MemberDTO"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%
	String id = request.getParameter("id");
	String password = request.getParameter("password");
	
	MemberDTO dto = new MemberDTO();
	
	dto.setId(id);
	dto.setPassword(password);
	
	MemberDAO dao = MemberDAO.getInstance();
	
	dto = dao.checkLogin(dto);		//id, password를 이용하여 dto에 id에 대한 정보 얻기
	
	boolean check = false;
	String msg = null;
		
	if(dto != null){
		msg = dto.getName() + "님이 로그인 하셨습니다.";
		check = true;
		
		//로그인 처리
		session.setAttribute("login", dto);
		
		//쿠키파일 처리...
		String ckid = request.getParameter("ckid");
		
		Cookie ck = null;
		
		Cookie[] cks = request.getCookies();
		
		if(cks != null){
			for(Cookie c : cks){
				if(c.getName().equals("ckid")){
					ck = c;
					break;
				}
			}
		}
		
		if(ckid != null){
			if(ck == null){
				ck = new Cookie("ckid",id);
				ck.setMaxAge(60*60*24);
				response.addCookie(ck);				
			}else{
				if(!ck.getValue().equals(id)){
					ck.setValue(id);
					ck.setMaxAge(60*60*24);
					response.addCookie(ck);
				}
			}
			
		}else{
			if(ck != null){
				if(ck.getValue().equals(id)){
					ck.setMaxAge(0);
					response.addCookie(ck);
				}
			}
		}
		
	}else{
		msg = "아이디 혹은 비밀번호가 잘못되었습니다.";
	}
	
	request.setAttribute("check", check);
	request.setAttribute("msg", msg);
	
	pageContext.forward("/login/result.jsp");
%>

















