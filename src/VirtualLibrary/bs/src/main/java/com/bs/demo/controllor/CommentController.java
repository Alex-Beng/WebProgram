package com.bs.demo.controllor;

import com.bs.demo.pojo.Comment;
import com.bs.demo.result.Result;
import com.bs.demo.result.ResultFactory;
import com.bs.demo.service.CommentService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
public class CommentController {
    @Autowired
    CommentService commentService;

    @CrossOrigin
    @PostMapping(value = "api/comment")
    @ResponseBody
    public Result addComment(@RequestBody Comment comment){
        commentService.addItem(comment);
        return new Result(200);
    }

    @CrossOrigin
    @GetMapping(value = "api/allcomment")
    @ResponseBody
    public Result findAll(@RequestParam Integer bookid){
        List<Comment> resComment = commentService.lists(bookid);
        Result result = ResultFactory.buildSuccessResult(resComment);
        return result;
    }
}
