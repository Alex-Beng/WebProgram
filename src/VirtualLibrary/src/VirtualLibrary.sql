-- 虚拟屠猪馆数据库
-- 三张表
-- 人表；书表；借阅表

-- user table
SET FOREIGN_KEY_CHECKS=0;
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user` (
  `id` varchar(40) NOT NULL,
  `username` varchar(20) NOT NULL,
  `cellphone` varchar(20) NOT NULL,
  `address` varchar(40) NOT NULL,
  `email` varchar(30) DEFAULT NULL,
  `password` varchar(30) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
INSERT INTO `user` VALUES ('1', 'zhongfucheng', '13719193845', 'guangzhou', '403686131@11.fom', '123');
INSERT INTO `user` VALUES ('2', 'zhongfuche', '13719193840', 'guangzhou', '403686131@11.fom', '321');

-- book table
-- 书籍表
SET FOREIGN_KEY_CHECKS=0;
DROP TABLE IF EXISTS `book`;
CREATE TABLE `book` (
  `id` varchar(40) NOT NULL,
  `name` varchar(10) NOT NULL,
  `description` varchar(255) DEFAULT NULL,
  `author` varchar(10) DEFAULT NULL,
  `owner` varchar(40) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
INSERT INTO `book` VALUES ('233', '>>>', '', 'wo', '1');

-- 借阅表
SET FOREIGN_KEY_CHECKS=0;
DROP TABLE IF EXISTS `borrow`;
CREATE TABLE `borrow` (
  `bid` varchar(40) NOT NULL,
  `book_id` varchar(40) NOT NULL,
  `date` date NOT NULL,
  `pin_id` varchar(40) NOT NULL,
  `pout_id` varchar(40) NOT NULL,
  `state` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`bid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `borrow` VALUES ('1', '233', '2018-05-06', '1', '2', 0);
