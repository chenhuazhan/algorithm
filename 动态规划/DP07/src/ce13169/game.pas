program dddp_game;
 const
  maxn=20000;
 type
  bs=array[0..maxn]of boolean;
  ds=array[0..maxn]of longint;
 var
  yy,win:bs;
  sushu,min,max:ds;
  ii,n,m,s,sum:longint;
 procedure qiuss;
  var
   i,j:longint;
   t:boolean;
  begin
   for i:=2 to maxn do
    begin
     t:=true;
     for j:=2 to trunc(sqrt(i)+0.000001) do
      if i mod j=0 then begin
                         t:=false;
                         break;
                         end;
     if t then begin
                inc(s);
                sushu[s]:=i;
                end;
     end;
   end;
 procedure pre;
  begin
   fillchar(yy,sizeof(yy),false);
   fillchar(win,sizeof(win),false);
   fillchar(max,sizeof(max),0);
   fillchar(min,sizeof(min),0);
   yy[0]:=true;
   yy[1]:=true;
   win[0]:=false;
   win[1]:=false;
   max[0]:=0;
   max[1]:=0;
   sum:=0;
   end;
 procedure chuli(m:longint);
  var
   i:longint;
  begin
   if yy[m] then exit;
   yy[m]:=true;
   for i:=1 to s do
    begin
     if sushu[i]>m then break;
     chuli(m-sushu[i]);
     if win[m-sushu[i]]=false then begin
                 win[m]:=true;
                 exit;
                                    end;
     end;
   win[m]:=false;
  end;
 procedure suan(m:longint);
  var
   i:longint;
  begin
   if m=16 then
                write;
   if win[m] then begin
               if min[m]>0 then exit;
               for i:=1 to s do
                begin
                 if sushu[i]>m then break;
                 if (win[m-sushu[i]]=false) and ((max[m-sushu[i]]+1<min[m]) or (min[m]=0))
                        then min[m]:=max[m-sushu[i]]+1;
                 end;
                   end;
   if win[m]=false then begin
               if max[m]>0 then exit;
               for i:=1 to s do
                begin
                 if sushu[i]>m then break;
                 if min[m-sushu[i]]+1>max[m] then max[m]:=min[m-sushu[i]]+1;
                 end;
                         end;
   end;
 begin
  assign(input,'game.in');
  reset(input);
  assign(output,'game.out');
  rewrite(output);
  readln(n);
  qiuss;
  pre;
  chuli(20000);
  for ii:=2 to 20000 do
   suan(ii);
  for ii:=1 to n do
   begin
    readln(m);
    if win[m]=false then writeln(-1)
                    else writeln(min[m]);
    end;
  close(input);
  close(output);
 end.
