/////////////////////////////
//
//  得到网站的根路径
//
/////////////////////////////

var SiteRootURL = "";

// 得到本脚本所在的URL，通过计算相对URL可以得到网站的根所在的URL
for (var i=0; i < document.scripts.length; i++ )
{
	if ( document.scripts(i).id == "header" )
	{
		SiteRootURL = document.scripts(i).src;
		break;
	}
}

SiteRootURL = SiteRootURL.substring(0,SiteRootURL.lastIndexOf("/"));
SiteRootURL = SiteRootURL.substring(0,SiteRootURL.lastIndexOf("/")+1);


/////////////////////////////
//
//	加上CSS链接
//
////////////////////////////

function AddCSS() {
	if ( SiteRootURL != "" ) {
		var strScriptURL = SiteRootURL + "/css/article.css";
		// 加上CSS
		document.write("<link rel='stylesheet' type='text/css' href='" + strScriptURL + "'>");
	}
}

AddCSS();


