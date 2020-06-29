package com.bs.demo.controllor;

import com.bs.demo.pojo.BackBook;
import com.bs.demo.pojo.Book;
import com.bs.demo.pojo.ProcessApply;
import com.bs.demo.result.Result;
import com.bs.demo.result.ResultFactory;
import com.bs.demo.service.BookService;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

import java.util.Iterator;
import java.util.List;

import static com.sun.org.apache.xml.internal.security.keys.keyresolver.KeyResolver.iterator;
@RestController
public class BookController {
    @Autowired
    BookService bookService;

    @CrossOrigin
    @RequestMapping(value = "api/books")
    @ResponseBody
    public Result listBooks() {
        System.out.println("接到获取图书请求");
        List<Book> res = bookService.list();
        for(Book element : res)    {
            System.out.println(element.getId() + " "+ element.getName() + " "+ element.getDescripte());
        }
        Result result = ResultFactory.buildSuccessResult(res);
        System.out.println(result.getResult());
        return result;
    }

    @CrossOrigin
    @GetMapping(value = "api/books")
    @ResponseBody
    public Result myBooks(@RequestParam String username) {
        System.out.println("查阅所有的" + username + "的图书！！！");
        List<Book> books = bookService.personalBooks(username);
        for(Book element : books)    {
            System.out.println(element.getId() + " "+ element.getName());
        }
        System.out.println("完成查阅" + username + "的图书！！！");
        Result res = ResultFactory.buildSuccessResult(books);
        return res;
    }

    @CrossOrigin
    @GetMapping(value = "api/offshelf")
    @ResponseBody
    public Result offShelf(@RequestParam Integer bookid) {
        String bookname = bookService.offItem(bookid);
        Result res = new Result(200,bookname);
        return res;
    }

    @CrossOrigin
    @PostMapping(value = "api/back")
    @ResponseBody
    public Result back(@RequestBody BackBook backBook) {
        Integer bookid = backBook.getBookid();
        System.out.println("归还图书开始！！！");
        String bookname = bookService.backItem(bookid);
        Result res = new Result(200,bookname);
        System.out.println("归还图书完成！！！");
        return res;
    }
}
