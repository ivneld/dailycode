package vo;

import org.springframework.web.multipart.MultipartFile;

public class PhotoVO {
	private String title; // 
	private String filename;//
	
	//
	private MultipartFile photo;
	
	//setter & getter
	public String getTitle() {
		return title;
	}

	public String getFilename() {
		return filename;
	}

	public void setFilename(String filename) {
		this.filename = filename;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public MultipartFile getPhoto() {
		return photo;
	}

	public void setPhoto(MultipartFile photo) {
		this.photo = photo;
	}
}
