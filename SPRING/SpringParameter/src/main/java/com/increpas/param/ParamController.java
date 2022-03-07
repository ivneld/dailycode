package com.increpas.param;

import javax.servlet.http.HttpServletRequest;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

import vo.PersonVO;

@Controller
public class ParamController {

	//
	public static final String VIEWPATH = "/WEB-INF/views/person/";
	
	//url - /insertForm
	@RequestMapping("/insertForm")
	public String insertForm() {
		return VIEWPATH + "insertForm.jsp";
	}
	
	//
	@RequestMapping("/insert1")
	public String insert1(Model model,@RequestParam("name") String name,int age,String tel) {
		PersonVO vo = new PersonVO(name, age, tel);
		
		model.addAttribute("vo", vo);
		
		return VIEWPATH + "insertResult.jsp";
	}
	
	//
	@RequestMapping("/insert2")
	public String insert2(Model model,PersonVO vo) {
		
		model.addAttribute("vo", vo);
		
		return VIEWPATH + "insertResult.jsp";
	}
	
	@RequestMapping(value={"/insert","/"}, method = RequestMethod.GET)
	public String insertForm2() {
		return VIEWPATH + "insertForm.jsp";
	}
	
	@RequestMapping(value="/insert",method = RequestMethod.POST)
	public ModelAndView insert(/* Model model, */PersonVO vo) {
		
		//ModelAndView
		// - ModelView 
		
		ModelAndView mv = new ModelAndView(/* VIEWPATH + "insertResult.jsp" */);
		
		mv.setViewName(VIEWPATH + "insertResult.jsp");
		
		mv.addObject("vo",vo);
		
		return mv;
	}
	
}














