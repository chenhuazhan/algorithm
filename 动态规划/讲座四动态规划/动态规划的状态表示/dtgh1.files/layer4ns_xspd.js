function channel_lnk()
{
  //设置栏目的script,for ns4
  var mywidth

  if(screen.width>799) mywidth=screen.width/2;
  else mywidth=800/2;
  
  var d = 10;
  var h = -4; 
  var top = 74;
  var left;
  var width = 68-d;
  var height = 13;

  var left_a = new Array(-400,-311,-301,-233,-165,-97,-29,39,107,117,141,151,219,299,367);
  var left_c = new Array(-400,-301,-233,-165,-97,-29,39,151,219,299);

//  var channel = new Array("sgsy","mszx","xspd","jtjj","ykrd","jgtd","etly","jyxx","sgfwt","sglt");
  var channel_name= new Array("首页","名师在线","学生频道","教坛聚焦","迎考热点","教改天地","儿童乐园","教育信息","曙光服务台","曙光论坛");
  var channel_link= new Array("","mszx/index","xspd/index","jtjj/index","ykrd/index","jgtd/index","etly/index","jyxx/index","sgfwt/index","bbs/default1");

  for (var i = 1; i <num; i++)
  {
    if(i!=2)
    {
    left=mywidth+left_c[i]+d;
    if(i==8) width = 80-d-2;
    oneLayer = "<LAYER NAME=" + channel[i]  + " TOP=" + top + " LEFT=" + left;
    oneLayer += " WIDTH=" + width + " HEIGHT=" + height;
    oneLayer += " BGCOLOR=#99cc99>" + "<a class='titlelink' href=../" + channel_link[i] + ".asp>";
    oneLayer += channel_name[i] + "</a></LAYER>\n";
    document.write(oneLayer);
    width = 68-d;
    }
  }
    i=2;
    left=mywidth+left_c[i]+d;
    oneLayer = "<LAYER NAME=" + channel[i]  + " TOP=" + top + " LEFT=" + left;
    oneLayer += " WIDTH=" + width + " HEIGHT=" + height;
    oneLayer += " BGCOLOR=#003399><font class='pt9'>";
    oneLayer += channel_name[i] + "</font></LAYER>\n";
    document.write(oneLayer);

  document.mszx.clip.top=h;
  document.xspd.clip.top=h;
  document.jtjj.clip.top=h;
  document.ykrd.clip.top=h;
  document.jgtd.clip.top=h;
  document.etly.clip.top=h;
  document.jyxx.clip.top=h;
  document.sgfwt.clip.top=h;
  document.sglt.clip.top=h;

  document.mszx.clip.left=-d;
  document.xspd.clip.left=-d;
  document.jtjj.clip.left=-d;
  document.ykrd.clip.left=-d;
  document.jgtd.clip.left=-d;
  document.etly.clip.left=-d;
  document.jyxx.clip.left=-d;
  document.sgfwt.clip.left=-d;
  document.sglt.clip.left=-d;
}