function setColor(e)
{
  //这是一个设置层背景色的script.
  //channel为栏目名称，num为栏目数
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
  //这是一个设置层背景色的script.
  //channel为栏目名称，num为栏目数
  for(var i=0;i<num;i++)
  if(i!=2)
    if(e.target.name==channel[i])
    {
      e.target.bgColor = mygreen;
      break;      
    }  
}