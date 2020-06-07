<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>憨憨图书馆·登录</title>
        <link rel="shortcut icon" href="${pageContext.request.contextPath}/favicon.ico" type="image/x-icon"/>
        
        <link rel="stylesheet" type="text/css" href="${pageContext.request.contextPath}/css/site_global.css"/>
        <link rel="stylesheet" type="text/css" href="${pageContext.request.contextPath}/css/new_index.css" id="pagesheet"/>
        <link rel="stylesheet" type="text/css" href="${pageContext.request.contextPath}/css/skinSel.css"  id="" />
        <style type="text/css">
            html {
            -ms-touch-action: none;  /* 阻止windows Phone 的默认触摸事件 */
            }
        
            ul {
                list-style: none;
            }
    
            #pages {
                overflow: hidden;
            }
            .page {
                display: none;
                width: 100%;
                height: 100%;
                overflow: hidden;
                position: absolute;
                top: 0;
                left: 0;
            }
            .contain {
                width: 100%;
                height: 100%;
                display: none;
                position: relative;
                z-index: 0;
            }
            .current .contain,.slide .contain {
                display: block;
            }
            .current {
                display: block;
                z-index: 1;
            }
            .slide {
                display: block;
                z-index: 2;
            }
            .swipe {
                display: block;
                z-index: 3;
                transition-duration: 0ms !important;
                -webkit-transition-duration: 0ms !important;
            }
        
        /*    .page1 {
                background: #37c1e3;
            }
            .page2 {
                background: #009922;
            }
            .page3 {
                background: #992211;
            }
            .page4 {
                background: #ff00ff;
            }
            .page5 {
                background: #00ff00;
            }
            .page6 {
                background: #22ffff;
            }*/
            #navBar {
                z-index: 3;
                position: absolute;
                top: 10%;
                right: 3%;
            }
            #navBar .active {
                background: #ccc;
            }
    
    
            </style>
      </head>

<body>
    <!-- 登陆面板 -->
    <div id="login_page" class="login_page">
        <div id="login" class="login_box_m">
            <div class="content">
                <div class="logo">
                    <img src="/r/cms/www/lasttemp/images/index/logo.png" alt="logo" />
                </div>
                <div class="login_form">
                    <div class="login_form_title">
                        <h3>用户登录</h3>
                    </div>
                    <form name="frm" id="form" method="post" action="/login.jspx">
                        <div class="login_form_detail">
                            <!-- 登录表单 -->
                            <div class="left_side">
                                <div class="input_div">
                                    <i class="_icon _i-user"></i>
                                    <input type="text" id="username" name="username" class="" placeholder="用户名/读者证号" />
                                </div>
                                <div class="input_div psw">
                                    <i class="_icon _i-psw"></i>
                                    <input type="password" autocomplete="off" id="password" name="password" class=""
                                        placeholder="密码" />
                                </div>
                                <input type="hidden" name="returnUrl" value="http://www.gzlib.org.cn/" />
                                <input type="submit" class="sub_btn" value="登录" />

                                <a href="/forgetPassword.jspx" class="forgetPassword">忘记密码?</a>
                            </div>
                            <!-- 链接 -->
                            <div class="right_side">
                                <div class="div1">没有账号？</div>
                                <div class="div2"><a href="http://opac.gzlib.org.cn/opac/reader/register"
                                        class="reg-link online-reg"><i class="_i-24h">&nbsp;</i>在线办证</a></div>
                                <div class="div3"><a href="/register.jspx" class="reg-link guest-reg"><i
                                            class="_i-guest">&nbsp;</i>访客注册</a></div>
                            </div>
                        </div>
                    </form>
                </div>
            </div>
        </div>

    </div>
    <!-- 登陆面板END -->

    <!-- 顶部导航条 -->
    <div class="header">
        <!-- 登录按钮区域 -->
        <div class="login_area">
            <!-- 登录提示 -->
            <div class="login_box ">
                <a href="/login.jspx?returnUrl=http://www.gzlib.org.cn/login.jspx?returnUrl=http&#37;3A&#37;2F&#37;2Fwww.gzlib.org.cn&#37;2F&amp;locale=zh_CN&locale=zh_CN"
                    class="newicon ni-login"
                    onclick="Cms.pageSiteLink('','http://www.gzlib.org.cn/login.jspx?returnUrl=http&#37;3A&#37;2F&#37;2Fwww.gzlib.org.cn&#37;2F&amp;locale=zh_CN','登录','登录页面头部的登录按钮');">登录</a>
                <a href="/register.jspx"
                    onclick="Cms.pageSiteLink('','http://www.gzlib.org.cn/login.jspx?returnUrl=http&#37;3A&#37;2F&#37;2Fwww.gzlib.org.cn&#37;2F&amp;locale=zh_CN','注册','登录页面头部的注册按钮');"
                    target="_blank" class="newicon ni-reg">注册</a>
                <a href="http://opac.gzlib.org.cn/opac/reader/login"
                    onclick="Cms.pageSiteLink('','http://www.gzlib.org.cn/login.jspx?returnUrl=http&#37;3A&#37;2F&#37;2Fwww.gzlib.org.cn&#37;2F&amp;locale=zh_CN','续借','登录页面头部的续借按钮');"
                    target="_blank" class="newicon ni-xu">续借</a>

            </div>
            <!-- 登录提示end -->
        </div>
        <!-- 登录按钮区域 end -->

        <!-- 顶部导航按钮 -->
        <div class="top_nav">
            <a id="navtoggleBtn" href="javascript:;" class="toggle_nav_btn"></a>
            <div class="top_nav_link">
                <a href="http://www.gzlib.org.cn:80/" title="首页" alt="首页" class="active" target="_self">首页</a>
                <a href="/digitalresources.jhtml" title="资源" alt="资源" target="_self">资源</a>
                <a href="/servitems/index.jhtml" title="服务" alt="服务" target="_self">服务</a>
                <a href="/hdActForecast/index.jhtml" title="活动" alt="活动" target="_self">活动</a>
                <a href="/hudbookname/index.jhtml" title="互动" alt="互动" target="_self">互动</a>
                <a href="http://www.gzlib.org.cn/zzcckyq/index.jhtml" title="专题" alt="专题" target="_self">专题</a>
                <a href="/aboutlib/index.jhtml" title="关于广图" alt="关于广图" target="_self">关于广图</a>
            </div>
        </div>
    </div>
    <!-- 顶部导航end -->




</body>

</html>