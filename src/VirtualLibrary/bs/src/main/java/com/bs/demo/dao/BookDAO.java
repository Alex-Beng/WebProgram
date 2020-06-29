package com.bs.demo.dao;

import com.bs.demo.pojo.Book;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface BookDAO extends JpaRepository<Book,Integer> {
    Book findAllById(Integer bookid);
    List<Book> findByUsername(String username);
    List<Book> findByBorrower(String borrower);
    @Override
    <S extends Book> S save(S s);
}