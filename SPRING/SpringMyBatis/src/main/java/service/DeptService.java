package service;

import java.util.List;

import dao.DeptDAO;
import vo.DeptVO;
//데이터베이스에 직접적으로 접근하는 건 DAO지만 데이터를 뽑아내는 것은 Service
public class DeptService {
	private DeptDAO deptDao;
	
	public DeptService(DeptDAO deptDao) {
		this.deptDao = deptDao;
	}
	
	public List<DeptVO> selectList(){
		return deptDao.selectList();
	}
	
	public DeptVO selectOne(int deptno) {
		return deptDao.selectOne(deptno);
	}
	
	public boolean insert(DeptVO vo) {
		vo.setDeptno(deptDao.maxNo() + 1);
		
		boolean check = false;
		
		if(deptDao.insert(vo) != 0) {
			check = true;
		}
		
		return check;
	}
	
	public int update(DeptVO vo) {
		return deptDao.update(vo);
	}
	
	public void delete(int deptno) {
		deptDao.delete(deptno);
	}
}
