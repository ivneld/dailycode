package member.action;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import member.MemberDAO;
import member.MemberDTO;
import util.Action;

public class UpdateAction implements Action {

	@Override
	public void execute(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		MemberDTO login = (MemberDTO)request.getSession().getAttribute("login");
		
		MemberDTO dto = new MemberDTO();
		dto.setNo(login.getNo());
		dto.setEmail(login.getEmail());
		dto.setTel1(login.getTel1());
		dto.setTel2(login.getTel2());
		dto.setTel3(login.getTel3());
		
		boolean check = MemberDAO.getInstance().updateMember(dto);
		
		String msg = null;
		String url = null;
		
		if(check) {		//������Ʈ�� �Ϸ�Ǿ��� ���� ���ǰ��� �ٲ�
			login.setEmail(request.getParameter("email"));
			login.setTel1(request.getParameter("tel1"));
			login.setTel2(request.getParameter("tel2"));
			login.setTel3(request.getParameter("tel3"));
			msg = "�����Ϸ�!!MyPage��...";
			url = "/MyHome/member/myPage.jsp";
		}else{
			msg = "��������!!������������...";
			url = "/MyHome/member/updateForm.jsp";
		}
		
		request.setAttribute("msg", msg);
		request.setAttribute("url", url);
	}

}
