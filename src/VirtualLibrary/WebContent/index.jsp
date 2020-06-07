<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>

<head>
	<title>憨憨图书馆·首页</title>
	<link rel="shortcut icon" href="${pageContext.request.contextPath}/favicon.ico" type="image/x-icon" />

	<link rel="stylesheet" type="text/css" href="${pageContext.request.contextPath}/css/site_global.css" />
	<link rel="stylesheet" type="text/css" href="${pageContext.request.contextPath}/css/new_index.css" id="pagesheet" />
	<link rel="stylesheet" type="text/css" href="${pageContext.request.contextPath}/css/skinSel.css" id="" />
	<style type="text/css">
		html {
			-ms-touch-action: none;
			/* 阻止windows Phone 的默认触摸事件 */
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

		.current .contain,
		.slide .contain {
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

	<!--侧边导航 -->
	<div id="sidebox" class="side_box">
		<div id="sicons" class="sicons">

			<a href="https://weibo.com/5888729818" target="_blank" title="新浪微博" class="sicon si-3" alt="新浪微博"></a>
			<a href="/VirtualLibrary/images/qr.jpg" target="_blank" title="微信" class="sicon si-4" alt="微信"></a>

		</div>
		<a id="sidetoggle" onclick="$('#sicons').toggleClass('open');"></a>
	</div>
	<!-- 侧边导航end-->

	<div id="pages" class="main_pages">

		<div id="page1" class="page current">
			<div class="contain">


				<!-- 搜索 -->
				<div id="search" class="search_box ">
					<div class="logo_box">
						<img src="/VirtualLibrary/images/logo.png" alt="憨图" />
					</div>
					<!-- 搜索form -->
					<div class="search clearfix">


						<div class="form_group">

							<div id="divselect1" class="_divselect title_check">
								<select name="select1">
									<option value="option1">任意词</option>
									<option value="option2">题名</option>
									<option value="option3">著者</option>
								</select>

							</div>
							<input name="" type="hidden" value="title" id="inputselect1" />
							<span id="split" class="split"></span>
							<input id="q" name="q" class="keyword" data-value="" placeholder="" type="text" />
							<!--<i class="icon"></i>-->

						</div>
						<input class="submit_btn" type="button" onclick="checkSousoType();" value="检索" />
						<a id="sb2" class="submit_btn2" onclick="checkSousoType();"></a>
						<form action="http://www.gzlib.org.cn/search.jspx" method="post" id="qFrom">
							<input type="hidden" name="queryq" value="" />
							<input type="hidden" name="hotsearch" value="" />
						</form>
					</div>
					<!-- 搜索form end -->

				</div>
				<!-- 搜索end -->

				<!-- 版权 -->
				<div class="page-copy">
					<p>版权不所有©Alex Beng </p>
				</div>
				<!-- 版权END -->
			</div>
		</div>


	</div>

</html>