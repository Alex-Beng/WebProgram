package com.bs.demo.service;

import com.bs.demo.dao.BookDAO;
import com.bs.demo.dao.UserDAO;
import com.bs.demo.pojo.Book;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Sort;
import org.springframework.stereotype.Service;

import java.util.List;
@Service
public class BookService {
    @Autowired
    BookDAO bookDAO;

    public List<Book> list(){
        List<Book> books= bookDAO.findAll();
        return books;
    }

    public  List<Book> personalBooks(String name){
        List<Book> personalbooks = bookDAO.findByBorrower(name);
        return personalbooks;
    }

    public String offItem(Integer bookid){
        Book book = bookDAO.findAllById(bookid);
        String res = book.getName();
        bookDAO.deleteById(bookid);
        return res;
    }

    public String backItem(Integer bookid){
        Book book = bookDAO.findAllById(bookid);
        String res = book.getName();
        String username = book.getUsername();
        book.setBorrower(username);
        bookDAO.save(book);
        System.out.println(book.getBorrower());
        return res;
    }
}
