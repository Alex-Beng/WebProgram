package com.bs.demo.dao;

import com.bs.demo.pojo.Book;
import com.bs.demo.pojo.Borrower;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface  BorrowerDAO extends JpaRepository<Borrower,Integer> {
        List<Borrower> findBorrowerByMastername(String name);
        Borrower findAllById(Integer borrowerid);
}
