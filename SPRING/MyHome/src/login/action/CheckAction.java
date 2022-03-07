package login.action;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import member.MemberDAO;
import member.MemberDTO;
import util.Action;

public class CheckAction  implements Action {

	public void execute(HttpServletRequest request, HttpServletResponse response) {
		//
		//
		
		String id = request.getParameter("id");
		String password = request.getParameter("password");
		
		MemberDTO dto = new MemberDTO();
		
		dto.setId(id);
		dto.setPassword(password);
		
		MemberDAO dao = MemberDAO.getInstance();
		
		dto = dao.checkLogin(dto);
		
		boolean check = false;
		String msg = null;
		
		if(dto != null){
			msg = dto.getName() + "님이 로그인 하셨습니다.";
			check = true;
			
			HttpSession session = request.getSession();
			//
			session.setAttribute("login", dto);
			
			//
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
		
	}

}
