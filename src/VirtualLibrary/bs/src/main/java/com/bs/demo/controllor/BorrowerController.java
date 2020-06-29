package com.bs.demo.controllor;

import com.bs.demo.pojo.Borrower;
import com.bs.demo.pojo.ProcessApply;
import com.bs.demo.pojo.showBorrower;
import com.bs.demo.result.Result;
import com.bs.demo.result.ResultFactory;
import com.bs.demo.service.BorrowerService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
public class BorrowerController {
    @Autowired
    BorrowerService borrowerService;

    @CrossOrigin
    @RequestMapping(value = "api/apply")
    @ResponseBody
    public Result getApply(@RequestBody Borrower requestBorrower){
        int bookid = requestBorrower.getBookid();
        String mastername = requestBorrower.getMastername();
        String borrowername = requestBorrower.getBorrowername();
        System.out.println(mastername+" " + borrowername + " " +mastername.equals(borrowername));
        if(!mastername.equals(borrowername)){
            Borrower borrower = new Borrower();
            borrower.setBookid(bookid);
            borrower.setBorrowername(borrowername);
            borrower.setMastername(mastername);
            borrowerService.saveBorrower(borrower);
            return new Result(200);
        }
        else{
            return new Result(400);
        }
    }

    @CrossOrigin
    @GetMapping(value = "api/applyList")
    @ResponseBody
    public Result getApplyList(@RequestParam String name){
        System.out.println("申请获得所有的对 "+name+" 的图书的申请");
        List<showBorrower> res = borrowerService.lists(name);

        Result result = ResultFactory.buildSuccessResult(res);

        return result;
    }

    @CrossOrigin
    @PostMapping(value = "api/processApply")
    @ResponseBody
    public Result getApply(@RequestBody ProcessApply requestProcess){
        String op = requestProcess.getOpinion();
        Integer bookid = requestProcess.getBookid();
        Integer borrowerid = requestProcess.getBorrowerid();
        if(op.equals("agree")){
            borrowerService.deleteAndchange(bookid,borrowerid);
            Result res = new Result(200,"同意");
            return res;
        }
        else{
            borrowerService.deleteItem(borrowerid);
            String opinion = "refuse";
            Result res = new Result(200,opinion);
            System.out.println(res.getMessage());
            return res;
        }
    }
}
