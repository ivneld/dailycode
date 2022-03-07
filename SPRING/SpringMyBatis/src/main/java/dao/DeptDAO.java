package dao;

import java.util.List;

import org.apache.ibatis.session.SqlSession;

import vo.DeptVO;

public class DeptDAO {
	private SqlSession sqlSession;
	
	public void setSqlSession(SqlSession sqlSession) {
		this.sqlSession = sqlSession;
	}
	
	public List<DeptVO> selectList(){
		return sqlSession.selectList("dept.list");
	}
	
	public DeptVO selectOne(int deptno) {
		return sqlSession.selectOne("dept.selectOne",deptno);
	}
	
	public int insert(DeptVO vo) {
		return sqlSession.insert("dept.insert",vo);
	}
	
	public int maxNo() {
		return sqlSession.selectOne("dept.maxNo");
	}
	
	public int update(DeptVO vo) {
		return sqlSession.update("dept.update",vo);
	}
	
	public int delete(int deptno) {
		return sqlSession.delete("dept.delete",deptno);
	}
}
