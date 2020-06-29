package com.bs.demo.controllor;

import com.bs.demo.dao.BookDAO;
import com.bs.demo.pojo.Book;
import com.bs.demo.pojo.User;
import com.bs.demo.result.Result;
import com.bs.demo.result.ResultFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

@Controller
public class UploadController {
    @Autowired
    BookDAO bookDAO;

    @CrossOrigin
    @PostMapping(value ="api/upload")
    @ResponseBody
    public Result listBooks(@RequestBody Book requestBook) {
        System.out.println("图书名称："+requestBook.getName());
        System.out.println("拥有者："+requestBook.getUsername());
        System.out.println("详细信息："+requestBook.getDescripte());
        System.out.println("种类："+requestBook.getKind());
        System.out.println("图书图片："+requestBook.getPic());
        System.out.println("图书时间："+requestBook.getDate());
        Book book = new Book();

        book.setBorrower(requestBook.getUsername());
        book.setUsername(requestBook.getUsername());
        book.setName(requestBook.getName());
        book.setDescripte(requestBook.getDescripte());
        book.setKind(requestBook.getKind());
        book.setPic(requestBook.getPic());
        book.setDate(requestBook.getDate());

        bookDAO.save(book);
        return ResultFactory.buildSuccessResult("加上了");
    }
}
