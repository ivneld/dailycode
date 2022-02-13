package com.jsp.board;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Timestamp;
import java.util.ArrayList;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.sql.DataSource;

public class boardDAO {
	private static boardDAO instance = new boardDAO();
	private Connection conn;
	private PreparedStatement pstmt;
	private ResultSet rs;
	private DataSource ds;
	
	public static boardDAO getInstance() {
		return instance;
	}
	
	private boardDAO() {
		try {
			Context context = new InitialContext();
			this.ds = (DataSource)context.lookup("java:comp/env/jdbc/oracle");
		}catch(Exception e) {e.printStackTrace();}
		}
	
	private void close(Connection conn) {
		if(conn!=null)
			try {
				conn.close();
			}catch(Exception e) {e.printStackTrace();}
	}
	private void close(PreparedStatement pstmt) {
		if(pstmt!=null)
			try {
				pstmt.close();
			}catch(Exception e) {e.printStackTrace();}
	}
	private void close(ResultSet rs) {
		if(rs!=null)
			try {
				rs.close();
			}catch(Exception e) {e.printStackTrace();}
	}
	
	public ArrayList<boardDTO> boardList() {
		ArrayList<boardDTO> list = new ArrayList<>();
		String query = "selet * from board order by bId DESC";
		try {
			conn = ds.getConnection();
			pstmt = conn.prepareStatement(query);
			rs = pstmt.executeQuery();
			
			while(rs.next()) {
				int bId = rs.getInt("bId");
				String bName = rs.getString("bName");
				String bTitle = rs.getString("bTitle");
				String bContent = rs.getNString("bContent");
				Timestamp bDate = rs.getTimestamp("bDate");
				int bHit = rs.getInt("bHit");
				list.add(new boardDTO(bId,bName,bTitle,bContent,bDate,bHit));
			}
		}catch(Exception e) {e.printStackTrace();}
		finally {
			close(rs);
			close(pstmt);
			close(conn);
		}
		return list;
	}
	
	public int write(String bName, String bTitle, String bContent) {
		int result=0;
		String query="insert into board(bId,bName,bTitle,bContent, bhit) values(board_seq.nexval,?,?,?,0)";
		try {
			conn = ds.getConnection();
			pstmt = conn.prepareStatement(query);
			pstmt.setString(1, bName);
			pstmt.setString(2, bTitle);
			pstmt.setString(3,bContent);
			result = pstmt.executeUpdate();
		}catch(Exception e) {e.printStackTrace();}
		finally {
			close(pstmt);
			close(conn);
		}
		return result;
	}
	
	public boardDTO contentView(String strID) {
		boardDTO dto = null;
		upHit(strID);
		String query="select * from board where bId = ?";
		try {
			conn = ds.getConnection();
			pstmt = conn.prepareStatement(query);
			rs = pstmt.executeQuery();
			
			if(rs.next()) {
				int bId = rs.getInt("bId");
				String bName = rs.getString("bName");
				String bTitle = rs.getString("bTitle");
				String bContent = rs.getString("bContent");
				Timestamp bDate = rs.getTimestamp("bDate");
				int bHit = rs.getInt("bHit");
				dto = new boardDTO(bId,bName,bTitle,bContent,bDate,bHit);
			}
		}catch(Exception e) {e.printStackTrace();}
		finally {
			close(rs);
			close(pstmt);
			close(conn);
		}
		return dto;
	}

public void upHit(String strID) {
	String query = "update board set bHit = bHit +1 where bId = ?";
	try {
		conn = ds.getConnection();
		pstmt = conn.prepareStatement(query);
		pstmt.setInt(1, Integer.parseInt(strID));
		pstmt.executeUpdate();
	}catch(Exception e) {e.printStackTrace();}
	finally {
		close(pstmt);
		close(conn);
	}
}

public int modify(String bId, String bName, String bTitle, String bContent) {
	int result = 0;
	String query = "update board set bName = ?, bTitle = ?, bContent = ? where bId = ?";
	
	try {
		conn = ds.getConnection();
		pstmt = conn.prepareStatement(query);
		pstmt.setString(1, bName);
		pstmt.setString(2, bTitle);
		pstmt.setString(3, bContent);
		pstmt.setInt(4, Integer.parseInt(bId));
		result = pstmt.executeUpdate();
	}catch(Exception e) {e.printStackTrace();}
	finally {
		close(pstmt);
		close(conn);
	}
	return result;
}

public int delete(String bId) {
	int result = 0;
	String query = "delete from board where bId = ?";
	
	try {
		conn = ds.getConnection();
		pstmt = conn.prepareStatement(query);
		pstmt.setInt(1, Integer.parseInt(bId));
		result = pstmt.executeUpdate();
	}catch(Exception e) {e.printStackTrace();}
	finally {
		close(pstmt);
		close(conn);
	}
	return result;
}
}