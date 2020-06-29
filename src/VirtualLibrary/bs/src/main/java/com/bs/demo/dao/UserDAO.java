package com.bs.demo.dao;

import com.bs.demo.pojo.Book;
import com.bs.demo.pojo.User;
import org.springframework.data.jpa.repository.JpaRepository;

public interface UserDAO extends JpaRepository<User,Integer> {
    User findByUsername(String username);
    User getByUsernameAndPassword(String username,String password);
    <S extends User> S save(S s);
}
