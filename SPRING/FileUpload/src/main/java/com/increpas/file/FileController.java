package com.increpas.file;

import java.io.File;
import java.io.IOException;

import javax.servlet.ServletContext;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.multipart.MultipartFile;

import vo.PhotoVO;
import vo.PhotoVO2;

@Controller
public class FileController {

        //AutoWired - 자동 주입
        // - 파라미터로 객체를 받을 필요없이 자동으로 추가해주는 기능...
        @Autowired
        private ServletContext application;
        
        @RequestMapping("insertForm")
        public String insertForm() {
                return "insertForm";
        }
        
        @RequestMapping("/upload")
        public String upload(Model model,PhotoVO vo) throws IllegalStateException, IOException {
        
                String savePath = application.getRealPath("/resources/upload/");
                
                MultipartFile photo = vo.getPhoto();
                
                String filename = null;
                
                if(!photo.isEmpty()) {//업로드 된 파일이 있으면...
                        
                        //업로드된 실제파일명...
                        filename = photo.getOriginalFilename();
                        
                        //File객체 생성
                        File saveFile = new File(savePath,filename);
                        
                        
                        if(!saveFile.exists()) { //경로의 파일이 없으면...
                                saveFile.mkdirs(); //경로상의 폴더 또는 파일들을 모두 만들어준다..
                        }else { //경로의 파일이 있으면..
                                long time = System.currentTimeMillis();
                                
                                filename = String.format("%s%d%s", filename.substring(0, filename.lastIndexOf(".")),time,filename.substring(filename.lastIndexOf(".")));
                                
                                saveFile = new File(savePath,filename);
                        }
                        
                        //업로드된 파일은 MultipartResolver라는 클래스가 지정한 임시저장소에 저장되어 있다...
                        //파일이 일정시간이 지나면 사라지기 때문에 내가 지정한 경로로 복사해 준다...
                        
                        photo.transferTo(saveFile);
                        
                }
                
                vo.setFilename(filename);
                
                //디비연결 코드...
                
                model.addAttribute("vo", vo);
                
                return "inputResult";
                
        }
        @RequestMapping(value = {"insertForm2"})
        public String insertForm2() {
                return "insertForm2";
        }
        
        
        @RequestMapping("/upload2")
        public String upload2(PhotoVO2 vo,Model model) throws Exception{
                String webPath="/resources/upload/";
                String savePath = application.getRealPath(webPath);
                
                MultipartFile[] photos = vo.getPhoto();
                
                for(int i = 0; i < photos.length; i++) {
                        MultipartFile photo = photos[i];
                        
                        String filename = "no File";
                                
                        //업로드 된 파일이 있으면..
                        if(!photo.isEmpty()) {
                                filename = photo.getOriginalFilename();
                                
                                File saveFile = new File(savePath,filename);
                                
                                if(!saveFile.exists()) {
                                        saveFile.mkdirs();
                                }else {
                                        int hash = photo.hashCode();
                                        filename = String.format("%s-%d%s", filename.substring(0,filename.lastIndexOf(".")), hash,
                                                        filename.substring(filename.lastIndexOf(".")));
                                        saveFile = new File(savePath,filename);
                                }
                                
                                photo.transferTo(saveFile);
                                
                                if(i == 0) {
                                        vo.setFilename1(filename);
                                }else {
                                        vo.setFilename2(filename);
                                }
                        }
                        
                }
                
                model.addAttribute("vo", vo);
                return "inputResult2";
                
        }
        
}
















