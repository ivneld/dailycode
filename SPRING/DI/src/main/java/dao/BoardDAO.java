package dao;

import java.util.List;

public interface BoardDAO {
	//CRUD의 기능을 정의한다.
	int insert(Object ob);		//create
	List<String> selectList();	//Read
	int update(Object ob);		//Update
	int delete(int idx);		//delete
}
