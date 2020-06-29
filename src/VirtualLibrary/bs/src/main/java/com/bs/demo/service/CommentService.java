package com.bs.demo.service;

import com.bs.demo.dao.CommentDAO;
import com.bs.demo.pojo.Comment;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class CommentService {
    @Autowired
    CommentDAO commentDAO;

    public void addItem(Comment comment){
        commentDAO.save(comment);
    }

    public List<Comment> lists(Integer bookid){
        List<Comment> res = commentDAO.findAllByBookid(bookid);
        return res;
    }
}
