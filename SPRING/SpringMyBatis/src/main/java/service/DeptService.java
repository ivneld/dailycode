package service;

import java.util.List;

import dao.DeptDAO;
import vo.DeptVO;
//�����ͺ��̽��� ���������� �����ϴ� �� DAO���� �����͸� �̾Ƴ��� ���� Service
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
