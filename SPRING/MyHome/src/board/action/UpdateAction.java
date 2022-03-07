package board.action;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import board.boarddao.BoardDAO;
import board.boarddto.BoardDTO;
import member.MemberDAO;
import util.Action;

public class UpdateAction implements Action {

	@Override
	public void execute(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		BoardDTO dto = new BoardDTO();
		dto.setContent(request.getParameter("content").replaceAll("\r\n", "<br>"));
		dto.setTitle(request.getParameter("title"));
		dto.setSeq(Integer.parseInt(request.getParameter("seq")));
		boolean check = BoardDAO.getInstance().updateContent(dto);
		
		request.setAttribute("check", check);
		request.setAttribute("status", "update");
		request.setAttribute("url", "/MyHome/board/content.brd?seq="+dto.getSeq());
	}

}
