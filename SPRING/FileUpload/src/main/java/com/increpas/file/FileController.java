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

        //AutoWired - �ڵ� ����
        // - �Ķ���ͷ� ��ü�� ���� �ʿ���� �ڵ����� �߰����ִ� ���...
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
                
                if(!photo.isEmpty()) {//���ε� �� ������ ������...
                        
                        //���ε�� �������ϸ�...
                        filename = photo.getOriginalFilename();
                        
                        //File��ü ����
                        File saveFile = new File(savePath,filename);
                        
                        
                        if(!saveFile.exists()) { //����� ������ ������...
                                saveFile.mkdirs(); //��λ��� ���� �Ǵ� ���ϵ��� ��� ������ش�..
                        }else { //����� ������ ������..
                                long time = System.currentTimeMillis();
                                
                                filename = String.format("%s%d%s", filename.substring(0, filename.lastIndexOf(".")),time,filename.substring(filename.lastIndexOf(".")));
                                
                                saveFile = new File(savePath,filename);
                        }
                        
                        //���ε�� ������ MultipartResolver��� Ŭ������ ������ �ӽ�����ҿ� ����Ǿ� �ִ�...
                        //������ �����ð��� ������ ������� ������ ���� ������ ��η� ������ �ش�...
                        
                        photo.transferTo(saveFile);
                        
                }
                
                vo.setFilename(filename);
                
                //��񿬰� �ڵ�...
                
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
                                
                        //���ε� �� ������ ������..
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
















