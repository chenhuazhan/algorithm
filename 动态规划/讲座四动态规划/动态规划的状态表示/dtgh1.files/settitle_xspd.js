function settitle()
{
//设置栏目
  document.write("<table width='777' border='0' cellspacing='0' cellpadding='0' height='17'><tr bgcolor='#99cc99' valign='bottom'>"); 

//<!-- for ie and ns -->
  document.write("<td width='89' height='17' align='center' bgcolor='#ffffff'><a class='titlelink' href='../index.htm'>返回首页</a></td>");
  document.write("<td width='10' height='17'><img src='images/0905-1_02.gif' width='10' height='17'></td>");

//<!-- for ie only -->
  if(!ns4)
  {
    document.write("<td width='68' onMouseOver='this.style.background=myyellow' onMouseOut='this.style.background=mygreen'><div align='center'><a class='titlelink' href='../mszx/index.asp'>名师在线</a></div></td>");
    document.write("<td width='68' STYLE='color:#ffffff' bgcolor='#003399'><div align='center'>学生频道</div></td>")
    document.write("<td width='68' onMouseOver='this.style.background=myyellow' onMouseOut='this.style.background=mygreen'><div align='center'><a class='titlelink' href='../jtjj/index.asp'>教坛聚焦</a></div></td>")
    document.write("<td width='68' onMouseOver='this.style.background=myyellow' onMouseOut='this.style.background=mygreen'><div align='center'><a class='titlelink' href='../ykrx/index.asp'>迎考热点</a></div></td>")
    document.write("<td width='68' onMouseOver='this.style.background=myyellow' onMouseOut='this.style.background=mygreen'><div align='center'><a class='titlelink' href='../jgtd/index.asp'>教改天地</a></div></td>")
    document.write("<td width='68' onMouseOver='this.style.background=myyellow' onMouseOut='this.style.background=mygreen'><div align='center'><a class='titlelink' href='../etly/index.asp'>儿童乐园</a></div></td>")
  }
//<!-- for ns only-->
  else
    document.write("<td width='408'></td>");


//<!-- for ie and ns -->
  document.write("<td width='10'><img src='images/0905-1_03.gif' width='10' height='17'></td>")
  document.write("<td width='24' align='center' bgcolor='#ffffff'>　</td>")
  document.write("<td width='10'><img src='images/0905-1_02.gif' width='10' height='17'></td>")

//<!-- for ie only -->
  if(!ns4)
  {
    document.write("<td width='68' onMouseOver='this.style.background=myyellow' onMouseOut='this.style.background=mygreen'><div align='center'><a class='titlelink' href='../jyxx/index.asp'>教育信息</a></div></td>");
    document.write("<td width='80' onMouseOver='this.style.background=myyellow' onMouseOut='this.style.background=mygreen'><div align='center'><a class='titlelink' href='../sgfwt/index.asp'>曙光服务台</a></div></td>");
    document.write("<td width='68' onMouseOver='this.style.background=myyellow' onMouseOut='this.style.background=mygreen'><div align='center'><a class='titlelink' href='../bbs/default1.asp'>曙光论坛</a></div></td>");
  }

//<!-- for ns only -->
  else
    document.write("<td width='216' align='center'>　</td>");

  document.write("<td width='10'><img src='images/0905-1_03.gif' width='10' height='17'></td></tr>");
  document.write("</table>");
}
