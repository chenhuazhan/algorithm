function adbanner()
{
  var how_many_ads = 1;   //显示广告条的数目，随便改，只要与下面的程序对应即可
  var width=468;          //广告条宽度
  var height=60;          //广告条高度
  var now = new Date();
  var sec = now.getSeconds();
  var ad = sec % how_many_ads;

  if(how_many_ads!=1)
  {
    ad +=1;
    if (ad==1)  //第一条广告条代码
    {                         
      url="http://www.chinaschool.org";     //相应的URL连接
      alt="广告条";
      banner="banner1.gif";          //广告条图片的URL 
    }

    if (ad==2)  //第二条广告条代码
    {                   
      url="http://www.chinaschool.org";
      alt="广告条";
      banner="banner2.gif";
    }

    if (ad==3)  //第三条广告条代码
    {                         
      url="http://www.chinaschool.org";
      alt="广告条";
      banner="banner3.gif";
    }
  }
  else
  {
    url="http://www.chinaschool.org/xspd.asp";     //相应的URL连接
    alt="广告条";
    banner="banner1.gif";          //广告条图片的URL 
  }  
  document.write('<div align="center">');
  document.write('<a href=' + url + '/\>');
  document.write('<img src=' + banner + ' width=')
  document.write(width + ' height=' + height + ' ');
  document.write('alt=' + alt + ' border=0>');
  document.write('</a></div>');
}