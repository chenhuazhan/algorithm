function setColor(e)
{
  //����һ�����ò㱳��ɫ��script.
  //channelΪ��Ŀ���ƣ�numΪ��Ŀ��
  for(var i=0;i<num;i++)
  if(i!=2)
    if(e.target.name==channel[i])
    {
      e.target.bgColor = myyellow;
      break;      
    }  
}

function setColorOrg(e) 
{
  //����һ�����ò㱳��ɫ��script.
  //channelΪ��Ŀ���ƣ�numΪ��Ŀ��
  for(var i=0;i<num;i++)
  if(i!=2)
    if(e.target.name==channel[i])
    {
      e.target.bgColor = mygreen;
      break;      
    }  
}