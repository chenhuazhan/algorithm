program dddp_robot;
 const
  maxn=101;
  maxm=1000;
  rule:array[0..3,1..2]of longint=((-1,0),
                                   (0,1),
                                   (1,0),
                                   (0,-1));
 type
  bb=array[0..maxn,0..maxn,0..3]of longint;
  bs=array[0..1]of bb;
  cs=array[0..maxn,0..maxn]of boolean;
  ds=array[1..maxm,1..2]of longint;
 var
  max:bs;
  info:cs;
  com:ds;
  n,m,x0,y0:longint;
 procedure pre;
  var
   i,j:longint;
   t:char;
  begin
   fillchar(info,sizeof(info),false);
   readln(n,m,x0,y0);
   for i:=1 to n do
    begin
     for j:=1 to n do
      begin
       read(t);
       if t='.' then info[i,j]:=true
                else info[i,j]:=false;
       end;
     readln;
     end;
   for i:=1 to m do
    begin
     read(t);
     readln;
     if t='L' then com[i,2]:=-1;
     if t='R' then com[i,2]:=1;
     if t='F' then com[i,1]:=1;
     if t='B' then com[i,1]:=-1;
     end;
   end;
 procedure chuli;
  var
   i,x,y,k,t,tx,ty,tk,z:longint;
  begin
   t:=0;
   for x:=1 to n do
    for y:=1 to n do
     for k:=0 to 3 do
      max[t,x,y,k]:=-1000000;
   max[t,x0,y0,0]:=0;
   for i:=1 to m do
    begin
     t:=i mod 2;
     for x:=1 to n do
      for y:=1 to n do
       for k:=0 to 3 do
        max[t,x,y,k]:=-1000000;
     for x:=1 to n do
      for y:=1 to n do
       if info[x,y] then
        for k:=0 to 3 do
         if max[1-t,x,y,k]>=0 then
          begin
           if max[1-t,x,y,k]>max[t,x,y,k] then max[t,x,y,k]:=max[1-t,x,y,k];
           tk:=(k+com[i,2]+4) mod 4;
           tx:=x+rule[tk,1]*com[i,1];
           ty:=y+rule[tk,2]*com[i,1];
           if (info[tx,ty]) and (max[1-t,x,y,k]+1>max[t,tx,ty,tk])
                then max[t,tx,ty,tk]:=max[1-t,x,y,k]+1;
           end;
     end;
   z:=0;
   for x:=1 to n do
    for y:=1 to n do
     for k:=0 to 3 do
      if max[n mod 2,x,y,k]>z then z:=max[n mod 2,x,y,k];
   writeln(m-z);
  end;
 begin
  assign(input,'robot.in');
  reset(input);
  assign(output,'robot.out');
  rewrite(output);
  pre;
  chuli;
  close(input);
  close(output);
 end.
