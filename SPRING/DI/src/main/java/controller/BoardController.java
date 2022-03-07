package controller;

import java.util.List;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import service.BoardService;

//@Component - Repository, Service, Controller�� �θ� Ŭ����
//- �뵵�� �°� Component���ٴ� �뵵�� �´� Ŭ������ ���°��� �����Ѵ�
//@Repository
//@Service
//@Controller

@Controller //�ش� Ŭ������ Controller��� ���� �νĽ�Ų��.
public class BoardController {
	private BoardService service;
	
	public void setService(BoardService service) {
		this.service = service;
	}
	
	public BoardController() {
		System.out.println("--- BoardController()�� ������ ---");
	}
	
	@RequestMapping("/board/list") //Webservlet�� ���� ����..
	//URL�� Method�� Mapping
	public String list(Model model) {
		List<String> list = service.selectList();
		//Model - �������̽�
		// - Servlet�� Controller�� �߰� �Ű�ü ����
		// - request������ binding ó���� �Ǿ� �ִ�.
		
		//request.setAttribute�� ���� ����
		model.addAttribute("list",list);
		
		return "list";	//WEB-INF/views/list.jsp�� ����.. ������ ���
	}
}

















