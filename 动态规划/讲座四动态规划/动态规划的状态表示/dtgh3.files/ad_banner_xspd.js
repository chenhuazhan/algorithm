function adbanner()
{
  var how_many_ads = 1;   //��ʾ���������Ŀ�����ģ�ֻҪ������ĳ����Ӧ����
  var width=468;          //��������
  var height=60;          //������߶�
  var now = new Date();
  var sec = now.getSeconds();
  var ad = sec % how_many_ads;

  if(how_many_ads!=1)
  {
    ad +=1;
    if (ad==1)  //��һ�����������
    {                         
      url="http://www.chinaschool.org";     //��Ӧ��URL����
      alt="�����";
      banner="banner1.gif";          //�����ͼƬ��URL 
    }

    if (ad==2)  //�ڶ������������
    {                   
      url="http://www.chinaschool.org";
      alt="�����";
      banner="banner2.gif";
    }

    if (ad==3)  //���������������
    {                         
      url="http://www.chinaschool.org";
      alt="�����";
      banner="banner3.gif";
    }
  }
  else
  {
    url="http://www.chinaschool.org/xspd.asp";     //��Ӧ��URL����
    alt="�����";
    banner="banner1.gif";          //�����ͼƬ��URL 
  }  
  document.write('<div align="center">');
  document.write('<a href=' + url + '/\>');
  document.write('<img src=' + banner + ' width=')
  document.write(width + ' height=' + height + ' ');
  document.write('alt=' + alt + ' border=0>');
  document.write('</a></div>');
}