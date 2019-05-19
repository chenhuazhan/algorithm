
//===================================
// �Ժ���Ҫ�õ��ı�������ֵ
//===================================

if (typeof(topic) == "undefined") topic = "";

if (typeof(previous) == "undefined" || previous == "end" || previous == "") {
	previous = "��һҳ | ";
} else {
	previous = "<a href='"+previous+"'>��һҳ</a> | ";
}

if (typeof(contents) == "undefined" || contents == "") {
	contents ="����Ŀ¼ | ";
} else {
	contents ="<a href='"+contents+"'>����Ŀ¼</a> | ";
}

if (typeof(next) == "undefined" || next == "end" || next == "") {
	next = "��һҳ";
} else {
	next = "<a href='"+next+"'>��һҳ</a>";
}

var gotop = "<a href='#'>����ҳ��</a> | ";


//===================================
//  ����Ĵ���������ӱ���
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
//   ���ҳ��ײ��ĵ�����
//===================================

function AddBottomNavBar() {
	var bottom_nav = "<p align='right' class ='nav_bar'>" + 
					 previous + contents + gotop + next +
					 "</p>";
	document.write(bottom_nav);
}

AddBottomNavBar();


//===================================
//   ���ҳ��ײ���banner
//===================================

function AddFooterBanner() {
	var sd=document.lastModified.toString();
	sd=sd.substring(0,sd.indexOf(" "));

	var	footer_banner=	'<hr style="height:1px;">'+
				'<p class="noindent" style="MARGIN-BOTTOM: 5px; MARGIN-TOP: 5px"><font color="#808080" size="2">'+
				'��ҳ���һ�θ�����'+
				sd+
				'<br>'+
				'email: <a href="mailto:starfish@vip.sina.com">starfish@vip.sina.com</a>'+
				'<br>'+
				'&copy;2000 �㷨�����ݽṹ <a href="http://algorithm.126.com/">http://algorithm.126.com/</a> '+
				'��Ȩ���� ת���뱣������'+
				'</font></p>';
	document.write(footer_banner);
}

AddFooterBanner()

//===================================
// ���ü�����
//===================================

function AddCounter() {

	if ( ( location.protocol != "file:" ) && 
		( location.hostname != "localhost" ) )
	{
		document.write("<div class='counter' style='display:none;'>");
		document.write( "<table width='100%' border='0'>" );
		document.write( "<tr align='center'>" );
		document.write( "<td><img border='0' src='http://202.103.132.176/cgi-bin/Count.cgi?df=Algorithm.dat&amp;ft=4'><br> " );
		document.write( "<a href=http://www.topcn.com/siteinfo.asp?UserName=Algorithm&SiteType=0 target=_blank><img src=http://www1.topcn.com:8081/statistics.asp?Algorithm&referURL="+escape(top.document.referrer)+"&curURL="+escape(top.document.URL)+"&imgStyle=0"+" border=0 width=20 height=20 alt='Top������վ������' ></a>" );
		document.write( "&nbsp;&nbsp;");
		document.write( "<a href=http://www.textclick.com/viewmain.asp?name=algorithm target=_blank><img src=http://ad.t2t2.com/stat.asp?user=algorithm&refer="+escape(document.referrer)+"&cur="+escape(document.URL)+" alt=̫��ͳ�� border=0></a><br>" );	
		document.write( "</td>" );
		document.write( "</tr>" );
		document.write( "</table>" );
		document.write("</div>");
	}
}

AddCounter();

//=========================
//   ����Ĵ�������ͬ����λ
//=========================

/*
if (parent.fraToc!=null) 
{
s=location.href;
parent.fraToc.locate(s);
}
*/

//==========================
//   �����Ǵ���cookie�Ĵ���
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
//    ����Ĵ��뽫����cookie���趨�Զ��л��������
//==============================================

var Langue=new Array("pascal","c++"); // Langue�ǿ��õı������

function SetLangue()
{	
	if (!navigator.cookieEnabled) //���û�д�cookie
	{
		alert("Ϊ��ʹ��������������վ���������������cookie���ô򿪣�лл��");
		return;
	} 
	var lang=GetCookie("langue");
	if (lang==null)  //�����ǰû��ָ���������
		if (parent.topFrame!=null)
		{
			parent.topFrame.select_langue();
			return;
		}
		else
		{		
			//alert("����û��ָ������ʹ�õı�����ԣ�����ϵͳ��ʹ��Ĭ�ϵı������pascal����ʾ��վ�����ݣ�������ͨ�����������Ϸ��ġ��趨������ԡ����ı��Ĭ�����á�");
			SetCookie("langue","pascal","/");
			lang="pascal";
		}
	if ( typeof(document.all.content) != "undefined" )
	{		
		var col=document.all.content.all.tags("CODE");
		if (col!=null)
			for (var i=0;i<col.length;i++)
			{
				if (col[i].className=="comment") col[i].style.display="none";  //�������е�ע�����
				for (var j=0;j<Langue.length;j++)  //�������е��������������Ե�����
					if (col[i].className==Langue[j]) {col[i].style.display="none";}
				if (col[i].className==lang) { col[i].style.display="block";} //��ʾ����ָ���ı������lang������		

				// ��α��������﷨˵��������
				if( (col[i].className=="pseudocode" )&&
					(typeof(SiteRootURL) != "undefined" ) &&
					(col[i].tagName=="CODE"))
				{
					var strHTML = "<p class='note' align='center'>������㷨ʹ����α���������������μ�<a href='" +
								  SiteRootURL + 
						          "algorithm/pseudocode.htm" +
					              "'>α�����ʹ��</a></p>";
					//alert(col[i].outerHTML);
					//alert(col[i].tagName);
					col[i].insertAdjacentHTML("AfterBegin",strHTML);	
				}

			}
	}
}

// �趨�������

//SetLangue();

