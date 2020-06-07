<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>

<head>
    <title>憨憨图书馆·登录</title>
    <link rel="shortcut icon" href="${pageContext.request.contextPath}/favicon.ico" type="image/x-icon" />

    
    <link rel="stylesheet" type="text/css" href="${pageContext.request.contextPath}/css/site_global.css" />
    <link rel="stylesheet" type="text/css" href="${pageContext.request.contextPath}/css/login.css" id="pagesheet" />
    <link rel="stylesheet" type="text/css" href="${pageContext.request.contextPath}/css/animate.css" id="" />
    
</head>

<body>
    <!-- 顶部导航条 -->
	<div class="header">
		<!-- 登录按钮区域 -->
		<div class="login_area">
			<!-- 登录提示 -->
			<div class="login_box">

				<a href="http://www.gzlib.org.cn/login.jspx?returnUrl=http%3A%2F%2Fwww.gzlib.org.cn%2F&amp;locale=zh_CN"
					title="登录" class="newicon ni-login">登录</a>
				<!--<a href="javascript:;" class="newicon ni-login">登录</a> -->
				<a href="javascript:;" id="reg" class="newicon showreg-btn ni-reg" title="注册">注册</a>

				<div class="top-reg" id="bothreg" style="display: none;">
					<a href="http://opac.gzlib.org.cn/opac/reader/register" class="top-reg-ol" target="_blank"
						title="在线注册"></a>
					<a href="register.htm" target="_blank" class="top-reg-guest" title="访客注册"></a>
				</div>
			</div>
			<!-- 登录提示end -->
		</div>
		<!-- 登录按钮区域 end -->
		<div class="top_nav">
			<div class="top_nav">
				<a id="navtoggleBtn" href="javascript:;" class="toggle_nav_btn"></a>
				<div class="top_nav_link">
					<a href="www_gzlib_org_default.html" title="首页" alt="首页" class="active" target="_self">首页</a>
					<a href="digitalresources.htm" title="资源" alt="资源" target="_self">资源</a>
					<a href="servitems/index.htm" title="服务" alt="服务" target="_self">服务</a>
					<a href="hdActForecast/index.htm" title="活动" alt="活动" target="_self">活动</a>
					<a href="hudbookname/index.htm" title="互动" alt="互动" target="_self">互动</a>
					<a href="http://www.gzlib.org.cn/zzcckyq/index.jhtml" title="专题" alt="专题" target="_self">专题</a>
					<a href="aboutlib/index.htm" title="关于憨图" alt="关于憨图" target="_self">关于憨图</a>
				</div>
			</div>

		</div>
	</div>
	<!-- 顶部导航end -->
    
    <!-- 登陆面板 -->
    <div id="login_page" class="login_page">
        <div id="login" class="login_box_m">
            <div class="content">
                <div class="logo">
                    <img src="/VirtualLibrary/images/logo.png" alt="logo" />
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
                                        class="reg-link online-reg"><i class="_i-24h">&nbsp;</i>立即注册</a></div>
                            </div>
                        </div>
                    </form>
                </div>
            </div>
        </div>

    </div>
    <!-- 登陆面板END -->
</body>

</html>