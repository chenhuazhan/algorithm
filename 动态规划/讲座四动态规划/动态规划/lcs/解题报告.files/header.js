/////////////////////////////
//
//  �õ���վ�ĸ�·��
//
/////////////////////////////

var SiteRootURL = "";

// �õ����ű����ڵ�URL��ͨ���������URL���Եõ���վ�ĸ����ڵ�URL
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
//	����CSS����
//
////////////////////////////

function AddCSS() {
	if ( SiteRootURL != "" ) {
		var strScriptURL = SiteRootURL + "/css/article.css";
		// ����CSS
		document.write("<link rel='stylesheet' type='text/css' href='" + strScriptURL + "'>");
	}
}

AddCSS();


