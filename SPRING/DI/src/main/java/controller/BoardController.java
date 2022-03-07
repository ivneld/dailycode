package controller;

import java.util.List;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import service.BoardService;

//@Component - Repository, Service, Controller의 부모 클래스
//- 용도에 맞게 Component보다는 용도에 맞는 클래스를 적는것을 권장한다
//@Repository
//@Service
//@Controller

@Controller //해당 클래스가 Controller라는 것을 인식시킨다.
public class BoardController {
	private BoardService service;
	
	public void setService(BoardService service) {
		this.service = service;
	}
	
	public BoardController() {
		System.out.println("--- BoardController()의 생성자 ---");
	}
	
	@RequestMapping("/board/list") //Webservlet과 같은 역할..
	//URL과 Method를 Mapping
	public String list(Model model) {
		List<String> list = service.selectList();
		//Model - 인터페이스
		// - Servlet과 Controller의 중간 매개체 역할
		// - request영역과 binding 처리가 되어 있다.
		
		//request.setAttribute와 같은 역할
		model.addAttribute("list",list);
		
		return "list";	//WEB-INF/views/list.jsp로 전달.. 포워드 방식
	}
}

















