program dddp_magic;
 const
  maxn=60;
  maxm=240;
  maxv=1000;
  maxk=30;
 type
  bs=array[1..maxn,1..2]of longint;
  cs=array[1..maxm,-1..maxn]of longint;
  dd=array[0..maxk]of longint;
  ds=array[0..maxn]of dd;
  es=array[0..maxv,0..maxk]of longint;
 var
  info:bs;
  make:cs;
  cost,temp:ds;
  max:es;
  n,m,v,kk:longint;
 procedure pre;
  var
   i,j:longint;
  begin
   readln(n,m,v,kk);
   fillchar(cost,sizeof(cost),10);
   for i:=1 to n do
    begin
     readln(info[i,1],info[i,2]);
     cost[i,0]:=info[i,1];
     end;
   for i:=1 to m do
    begin
     read(make[i,-1],make[i,0]);
     for j:=1 to make[i,0] do
      read(make[i,j]);
     readln;
     end;
   end;
 procedure suancost;
  var
   i,j,k,l,ll:longint;
   temp:ds;
  begin
   for i:=1 to kk do
    for j:=1 to m do
     begin
      fillchar(temp,sizeof(temp),10);
      temp[0,0]:=0;
      for k:=1 to make[j,0] do
       for l:=0 to i-1 do
        for ll:=0 to l do
         if temp[k-1,ll]+cost[make[j,k],l-ll]<temp[k,l]
                then temp[k,l]:=temp[k-1,ll]+cost[make[j,k],l-ll];
      if temp[make[j,0],i-1]<cost[make[j,-1],i]
        then cost[make[j,-1],i]:=temp[make[j,0],i-1];
      end;
   end;
 procedure chuli;
  var
   i,j,k,l,z:longint;
  begin
   fillchar(max,sizeof(max),0);
   for i:=1 to v do
    for j:=0 to kk do
     for k:=1 to n do
       for l:=0 to j do
        if (cost[k,l]<=i) and (max[i-cost[k,l],j-l]+info[k,2]-cost[k,l]>max[i,j])
                then max[i,j]:=max[i-cost[k,l],j-l]+info[k,2]-cost[k,l];
   z:=0;
   for i:=1 to v do
    for j:=0 to kk do
     if max[i,j]>z then z:=max[i,j];
   writeln(z);
   end;
 begin
  assign(input,'magic.in');
  reset(input);
  assign(output,'magic.out');
  rewrite(output);
  pre;
  suancost;
  chuli;
  close(input);
  close(output);
 end.