package com.bs.demo.service;

import com.bs.demo.dao.BookDAO;
import com.bs.demo.dao.BorrowerDAO;
import com.bs.demo.pojo.Book;
import com.bs.demo.pojo.Borrower;
import com.bs.demo.pojo.showBorrower;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.LinkedList;
import java.util.List;
import java.util.Optional;

@Service
public class BorrowerService {
    @Autowired
    BorrowerDAO borrowerDAO;
    @Autowired
    BookDAO bookDAO;
    public void saveBorrower(Borrower borrower){
        borrowerDAO.save(borrower);
        return;
    }

    public List<showBorrower> lists(String name){
        List<Borrower> borrowers = borrowerDAO.findBorrowerByMastername(name);
        List<showBorrower> showborrowers =  new LinkedList<showBorrower>();;
        for(Borrower item:borrowers){
            showborrowers.add(new showBorrower(item));
        }
        for(showBorrower item:showborrowers){
            System.out.println(item.getBorrower().getBookid() + " " +  item.getBorrower().getMastername() + " " +  item.getBorrower().getBorrowername());
            Book book= bookDAO.findAllById(item.getBorrower().getBookid());
            item.setBook(book);
        }
        return showborrowers;
    }
    public  void deleteAndchange(Integer bookid,Integer  borrowerid){
        Book book = bookDAO.findAllById(bookid);
        Borrower borrower = borrowerDAO.findAllById(borrowerid);
        book.setBorrower(borrower.getBorrowername());
        deleteItem(borrowerid);
    }
    public void deleteItem(Integer borrowerid){
        borrowerDAO.deleteById(borrowerid);
    }
}
