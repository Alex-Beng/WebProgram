package com.bs.demo.dao;

import com.bs.demo.pojo.Book;
import com.bs.demo.pojo.Borrower;
import com.bs.demo.pojo.Comment;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface  CommentDAO extends JpaRepository<Comment,Integer> {
    List<Comment> findAllByBookid(Integer bookid);
    @Override
    <S extends Comment> S save(S s);
}
