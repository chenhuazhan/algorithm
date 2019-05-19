var
x:array[0..5000,0..50]of longint;
k,v,n,i,j,l,ans,a,b,r,t:longint;

procedure xia(i,j:longint);
begin
	while j+j<=x[i,0] do begin
		r:=j+j;
		if (r+1<=x[i,0])and(x[i,r+1]<x[i,r]) then inc(r);
		if x[i,j]>x[i,r] then begin
			t:=x[i,j];
			x[i,j]:=x[i,r];
			x[i,r]:=t;
		end
		else break;
		j:=r;
	end;
end;

procedure shang(i,j:longint);
begin
	j:=j shr 1;
	while j<>0 do begin
		r:=j+j;
		if (r+1<=x[i,0])and(x[i,r+1]<x[i,r]) then inc(r);
		if x[i,j]>x[i,r] then begin
			t:=x[i,j];
			x[i,j]:=x[i,r];
			x[i,r]:=t;
		end
		else break;
		j:=j shr 1;
	end;
end;

begin
	assign(input,'bags.in');reset(input);
	assign(output,'bags.out');rewrite(output);
	readln(k,v,n);
	x[0,0]:=1;
	for i:=1 to n do begin
		readln(a,b);
		for j:=v downto a do begin
			for l:=x[j-a,0] downto 1 do begin
				if x[j,0]<k then begin
					inc(x[j,0]);
					x[j,x[j,0]]:=x[j-a,l]+b;
					shang(j,x[j,0]);
				end
				else if x[j-a,l]+b>x[j,1] then begin
					x[j,1]:=x[j-a,l]+b;
					xia(j,1);
				end;
			end;
		end;
	end;
	for i:=1 to k do begin
		inc(ans,x[v,i]);
	end;
	writeln(ans);
	close(output);
end.