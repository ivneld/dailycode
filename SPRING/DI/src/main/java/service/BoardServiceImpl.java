package service;

import java.util.List;

import dao.BoardDAO;

public class BoardServiceImpl implements BoardService{
	
	private BoardDAO dao;
	
	public BoardServiceImpl(BoardDAO dao) {
		this.dao = dao;
	}
	
	@Override
	public List<String> selectList() {
		// TODO Auto-generated method stub
		return null;
	}
}
