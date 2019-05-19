
//===================================
// 对后面要用到的变量赋初值
//===================================

if (typeof(topic) == "undefined") topic = "";

if (typeof(previous) == "undefined" || previous == "end" || previous == "") {
	previous = "上一页 | ";
} else {
	previous = "<a href='"+previous+"'>上一页</a> | ";
}

if (typeof(contents) == "undefined" || contents == "") {
	contents ="返回目录 | ";
} else {
	contents ="<a href='"+contents+"'>返回目录</a> | ";
}

if (typeof(next) == "undefined" || next == "end" || next == "") {
	next = "下一页";
} else {
	next = "<a href='"+next+"'>下一页</a>";
}

var gotop = "<a href='#'>返回页首</a> | ";


//===================================
//  下面的代码用来添加标题
//===================================


function AddTopNavBar() {
	if (typeof( document.all.content ) == "undefined") return;
	
	var header_html ='<table border="0" width="100%" cellspacing="1" cellpadding="0" style="border-bottom-width : 2px;border-style : solid; border-top-width : 0; border-right-width : 0; border-left-width : 0; "> ' +
					 '<tr>' +
					 '<td width="50%" align="left"><p class="topic_title">#TOPIC#</p></td>'+
					 '<td width="50%" align="right"><p class="nav_bar">#NAVBAR#</p></td>'+
					 '</tr>'+
					 '</table>';
		
	header_html = header_html.replace('#TOPIC#', topic);
	header_html = header_html.replace('#NAVBAR#',previous+contents+next);	
	document.all.content.insertAdjacentHTML( "afterBegin", header_html);
}

AddTopNavBar();


//===================================
//   添加页面底部的导航条
//===================================

function AddBottomNavBar() {
	var bottom_nav = "<p align='right' class ='nav_bar'>" + 
					 previous + contents + gotop + next +
					 "</p>";
	document.write(bottom_nav);
}

AddBottomNavBar();


//===================================
//   添加页面底部的banner
//===================================

function AddFooterBanner() {
	var sd=document.lastModified.toString();
	sd=sd.substring(0,sd.indexOf(" "));

	var	footer_banner=	'<hr style="height:1px;">'+
				'<p class="noindent" style="MARGIN-BOTTOM: 5px; MARGIN-TOP: 5px"><font color="#808080" size="2">'+
				'本页最后一次更新于'+
				sd+
				'<br>'+
				'email: <a href="mailto:starfish@vip.sina.com">starfish@vip.sina.com</a>'+
				'<br>'+
				'&copy;2000 算法与数据结构 <a href="http://algorithm.126.com/">http://algorithm.126.com/</a> '+
				'版权所有 转载请保留出处'+
				'</font></p>';
	document.write(footer_banner);
}

AddFooterBanner()

//===================================
// 放置计数器
//===================================

function AddCounter() {

	if ( ( location.protocol != "file:" ) && 
		( location.hostname != "localhost" ) )
	{
		document.write("<div class='counter' style='display:none;'>");
		document.write( "<table width='100%' border='0'>" );
		document.write( "<tr align='center'>" );
		document.write( "<td><img border='0' src='http://202.103.132.176/cgi-bin/Count.cgi?df=Algorithm.dat&amp;ft=4'><br> " );
		document.write( "<a href=http://www.topcn.com/siteinfo.asp?UserName=Algorithm&SiteType=0 target=_blank><img src=http://www1.topcn.com:8081/statistics.asp?Algorithm&referURL="+escape(top.document.referrer)+"&curURL="+escape(top.document.URL)+"&imgStyle=0"+" border=0 width=20 height=20 alt='Top中文网站龙虎榜' ></a>" );
		document.write( "&nbsp;&nbsp;");
		document.write( "<a href=http://www.textclick.com/viewmain.asp?name=algorithm target=_blank><img src=http://ad.t2t2.com/stat.asp?user=algorithm&refer="+escape(document.referrer)+"&cur="+escape(document.URL)+" alt=太极统计 border=0></a><br>" );	
		document.write( "</td>" );
		document.write( "</tr>" );
		document.write( "</table>" );
		document.write("</div>");
	}
}

AddCounter();

//=========================
//   下面的代码用来同步定位
//=========================

/*
if (parent.fraToc!=null) 
{
s=location.href;
parent.fraToc.locate(s);
}
*/

//==========================
//   下面是处理cookie的代码
//==========================


function SetCookie (name, value) {
         var argv = SetCookie.arguments;
         var argc = SetCookie.arguments.length;         
         var path = (argc > 2) ? argv[2] : null;
         var domain = (argc > 3) ? argv[3] : null;
		 var expires = (argc > 4) ? argv[4] : null;
         var secure = (argc > 5) ? argv[5] : false;
         document.cookie = name + "=" + escape (value) +
         ((expires == null) ? "" : ("; expires=" + expires.toGMTString())) +
         ((path == null) ? "" : ("; path=" + path)) +
         ((domain == null) ? "" : ("; domain=" + domain)) +
         ((secure == true) ? "; secure" : "");
}


function getCookieVal(offset) {
   var endstr = document.cookie.indexOf (";", offset);
   if (endstr == -1) endstr = document.cookie.length;
   return unescape (document.cookie.substring(offset, endstr));
}


function GetCookie(name) {
   var arg = name+"=";
   var alen = arg.length;
   var clen = document.cookie.length;
   var i = 0;
   while (i < clen) {
      var j = i + alen;
      if (document.cookie.substring(i, j) == arg) return getCookieVal(j);
      i = document.cookie.indexOf(" ", i) + 1;
      if (i == 0) break;
   }
   return null;
}


function DeleteCookie (name) {
  var argv = DeleteCookie.arguments;
  var argc = DeleteCookie.arguments.length;
  var path = (argc > 1) ? argv[1] : null;
  var domain = (argc > 2) ? argv[2] : null;
  if (GetCookie(name)) {
    document.cookie = name + "=" +
      ((path) ? "; path=" + path : "") +
      ((domain) ? "; domain=" + domain : "") +
      "; expires=Thu, 01-Jan-70 00:00:01 GMT";
  }
}

//==============================================
//    下面的代码将根据cookie的设定自动切换编程语言
//==============================================

var Langue=new Array("pascal","c++"); // Langue是可用的编程语言

function SetLangue()
{	
	if (!navigator.cookieEnabled) //如果没有打开cookie
	{
		alert("为了使您更方便地浏览本站，请您将浏览器的cookie设置打开，谢谢！");
		return;
	} 
	var lang=GetCookie("langue");
	if (lang==null)  //如果以前没有指定编程语言
		if (parent.topFrame!=null)
		{
			parent.topFrame.select_langue();
			return;
		}
		else
		{		
			//alert("您还没有指定您所使用的编程语言，下面系统将使用默认的编程语言pascal来显示网站的内容，您可以通过工具栏右上方的“设定编程语言”来改变此默认设置。");
			SetCookie("langue","pascal","/");
			lang="pascal";
		}
	if ( typeof(document.all.content) != "undefined" )
	{		
		var col=document.all.content.all.tags("CODE");
		if (col!=null)
			for (var i=0;i<col.length;i++)
			{
				if (col[i].className=="comment") col[i].style.display="none";  //隐藏所有的注释语句
				for (var j=0;j<Langue.length;j++)  //隐藏所有的依赖具体编程语言的内容
					if (col[i].className==Langue[j]) {col[i].style.display="none";}
				if (col[i].className==lang) { col[i].style.display="block";} //显示依赖指定的编程语言lang的内容		

				// 对伪代码加上语法说明的链接
				if( (col[i].className=="pseudocode" )&&
					(typeof(SiteRootURL) != "undefined" ) &&
					(col[i].tagName=="CODE"))
				{
					var strHTML = "<p class='note' align='center'>下面的算法使用了伪代码进行描述，请参见<a href='" +
								  SiteRootURL + 
						          "algorithm/pseudocode.htm" +
					              "'>伪代码的使用</a></p>";
					//alert(col[i].outerHTML);
					//alert(col[i].tagName);
					col[i].insertAdjacentHTML("AfterBegin",strHTML);	
				}

			}
	}
}

// 设定编程语言

//SetLangue();

