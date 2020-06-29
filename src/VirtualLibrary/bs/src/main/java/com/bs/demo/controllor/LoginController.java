package com.bs.demo.controllor;


import com.bs.demo.dao.UserDAO;
import com.bs.demo.pojo.User;
import com.bs.demo.result.Result;
import com.bs.demo.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.util.HtmlUtils;



import java.util.Objects;

@Controller
public class LoginController {

    @Autowired
    UserService userService;
    @Autowired
    UserDAO userDAO;

    @CrossOrigin
    @PostMapping(value = "api/login")
    @ResponseBody
    public Result login(@RequestBody User requestUser) {
    // 对 html 标签进行转义，防止 XSS 攻击
        String username = requestUser.getUsername();
        username = HtmlUtils.htmlEscape(username);
        User user = userService.get(username,requestUser.getPassword());
        if(null == user){
            System.out.println(400);
            return new Result(400);
        }
        else{
            System.out.println(200);
            System.out.println(username+"登陆成功");
            return new Result(200);
        }
    }

    @CrossOrigin
    @PostMapping(value = "api/register")
    @ResponseBody
    public Result register(@RequestBody User requestUser){
        String username = requestUser.getUsername();
        String password = requestUser.getPassword();
        User user = userService.getByName(username);
        if(user == null){
            System.out.println(username + "Registering");
            User register = new User();
            register.setUsername(username);
            register.setPassword(password);
            userDAO.save(register);
            System.out.println(username + "Registered");
            return new Result(200);
        }
        else{
            return new Result(400);
        }
    }
}