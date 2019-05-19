program dddp_bags;
 const
  maxk=50;
  maxv=5000;
  maxn=200;
 type
  bs=array[1..maxn,1..2]of longint;
  cc=array[1..maxk]of longint;
  cs=array[0..maxv]of cc;
 var
  info:bs;
  max:cs;
  temp:cc;
  n,v,k:longint;
 procedure pre;
  var
   i:longint;
  begin
   readln(k,v,n);
   for i:=1 to n do
    readln(info[i,1],info[i,2]);
   end;
 procedure fu(t1,kk,t2:longint);
  var
   i,top1,top2:longint;
  begin
   top1:=1;
   top2:=1;
   fillchar(temp,sizeof(temp),0);
   for i:=1 to k do
    begin
     if (max[t1,top1]=0) and (max[t2,top2]=0) then break;
     if (max[t1,top1]>0) and (max[t1,top1]+kk>max[t2,top2])
        then begin
              temp[i]:=max[t1,top1]+kk;
              inc(top1);
              end
        else begin
              temp[i]:=max[t2,top2];
              inc(top2);
              end;
     end;
   max[t2]:=temp;
   end;
 procedure inse(kk,jj:longint);
  var
   i,j:longint;
  begin
   for i:=1 to k do
    if max[jj,i]<kk then begin
              for j:=k downto i+1 do
               max[jj,j]:=max[jj,j-1];
              max[jj,i]:=kk;
              exit;
                          end;
   end;
 procedure chuli;
  var
   i,j,s:longint;
  begin
   for i:=1 to n do
    for j:=v downto info[i,1] do
     begin
      if j<>info[i,1] then fu(j-info[i,1],info[i,2],j)
                      else inse(info[i,2],j);
      end;
   s:=0;
   for i:=1 to k do
    inc(s,max[v,i]);
   writeln(s);
   end;
 begin
  assign(input,'bags.in');
  reset(input);
  assign(output,'bags.out');
  rewrite(output);
  pre;
  chuli;
  close(input);
  close(output);
 end.