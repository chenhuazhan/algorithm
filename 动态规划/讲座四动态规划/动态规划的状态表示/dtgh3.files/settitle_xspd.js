function settitle()
{
//������Ŀ
  document.write("<table width='777' border='0' cellspacing='0' cellpadding='0' height='17'><tr bgcolor='#99cc99' valign='bottom'>"); 

//<!-- for ie and ns -->
  document.write("<td width='89' height='17' align='center' bgcolor='#ffffff'><a class='titlelink' href='../index.htm'>������ҳ</a></td>");
  document.write("<td width='10' height='17'><img src='images/0905-1_02.gif' width='10' height='17'></td>");

//<!-- for ie only -->
  if(!ns4)
  {
    document.write("<td width='68' onMouseOver='this.style.background=myyellow' onMouseOut='this.style.background=mygreen'><div align='center'><a class='titlelink' href='../mszx/index.asp'>��ʦ����</a></div></td>");
    document.write("<td width='68' STYLE='color:#ffffff' bgcolor='#003399'><div align='center'>ѧ��Ƶ��</div></td>")
    document.write("<td width='68' onMouseOver='this.style.background=myyellow' onMouseOut='this.style.background=mygreen'><div align='center'><a class='titlelink' href='../jtjj/index.asp'>��̳�۽�</a></div></td>")
    document.write("<td width='68' onMouseOver='this.style.background=myyellow' onMouseOut='this.style.background=mygreen'><div align='center'><a class='titlelink' href='../ykrx/index.asp'>ӭ���ȵ�</a></div></td>")
    document.write("<td width='68' onMouseOver='this.style.background=myyellow' onMouseOut='this.style.background=mygreen'><div align='center'><a class='titlelink' href='../jgtd/index.asp'>�̸����</a></div></td>")
    document.write("<td width='68' onMouseOver='this.style.background=myyellow' onMouseOut='this.style.background=mygreen'><div align='center'><a class='titlelink' href='../etly/index.asp'>��ͯ��԰</a></div></td>")
  }
//<!-- for ns only-->
  else
    document.write("<td width='408'></td>");


//<!-- for ie and ns -->
  document.write("<td width='10'><img src='images/0905-1_03.gif' width='10' height='17'></td>")
  document.write("<td width='24' align='center' bgcolor='#ffffff'>��</td>")
  document.write("<td width='10'><img src='images/0905-1_02.gif' width='10' height='17'></td>")

//<!-- for ie only -->
  if(!ns4)
  {
    document.write("<td width='68' onMouseOver='this.style.background=myyellow' onMouseOut='this.style.background=mygreen'><div align='center'><a class='titlelink' href='../jyxx/index.asp'>������Ϣ</a></div></td>");
    document.write("<td width='80' onMouseOver='this.style.background=myyellow' onMouseOut='this.style.background=mygreen'><div align='center'><a class='titlelink' href='../sgfwt/index.asp'>������̨</a></div></td>");
    document.write("<td width='68' onMouseOver='this.style.background=myyellow' onMouseOut='this.style.background=mygreen'><div align='center'><a class='titlelink' href='../bbs/default1.asp'>�����̳</a></div></td>");
  }

//<!-- for ns only -->
  else
    document.write("<td width='216' align='center'>��</td>");

  document.write("<td width='10'><img src='images/0905-1_03.gif' width='10' height='17'></td></tr>");
  document.write("</table>");
}
