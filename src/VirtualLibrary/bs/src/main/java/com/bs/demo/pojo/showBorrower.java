package com.bs.demo.pojo;

public class showBorrower {
    private Book book;
    private Borrower borrower;
    public showBorrower(Borrower bor){
        this.borrower = bor;
    }
    public Book getBook() {
        return book;
    }

    public void setBook(Book book) {
        this.book = book;
    }

    public Borrower getBorrower() {
        return borrower;
    }

    public void setBorrower(Borrower borrower) {
        this.borrower = borrower;
    }
}
