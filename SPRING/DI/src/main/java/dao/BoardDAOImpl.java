package dao;

import java.util.ArrayList;
import java.util.List;

public class BoardDAOImpl implements BoardDAO{

	@Override
	public List<String> selectList() {
		List<String> list = new ArrayList<String>();
		
		list.add("사과");
		list.add("딸기");
		list.add("수박");
		
		return list;
}
	
	@Override
	public int delete(int idx) {
		// TODO Auto-generated method stub
		return 0;
	}
	
	@Override
	public int insert(Object ob) {
		// TODO Auto-generated method stub
		return 0;
	}
	
	@Override
	public int update(Object ob) {
		// TODO Auto-generated method stub
		return 0;
	}
	
	
}
