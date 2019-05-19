var
z:array[0..1000,0..30]of longint;
y:array[1..240,-1..60]of longint;
x:array[1..60,-1..30]of longint;
b:array[0..30]of longint;
n,m,v,k,i,j,l,r:longint;

procedure dfs(i,j:longint);
var
k,l,r,d:longint;
begin
	x[j,i]:=x[j,i-1];
	for k:=1 to m do if y[k,-1]=j then begin
		fillchar(b,sizeof(b),0);
		for l:=1 to y[k,0] do begin
			for r:=i-1 downto 0 do begin
				b[r]:=b[r]+x[y[k,l],0];
				for d:=1 to r do begin
					if b[r]>b[r-d]+x[y[k,l],d] then b[r]:=b[r-d]+x[y[k,l],d];
				end;
			end;
		end;
		if b[i-1]<x[j,i] then x[j,i]:=b[i-1];
	end;
end;

begin
	assign(input,'magic.in');reset(input);
	assign(output,'magic.out');rewrite(output);
	readln(n,m,v,k);
	for i:=1 to n do begin
		readln(x[i,0],x[i,-1]);
	end;
	for i:=1 to m do begin
		read(y[i,-1],y[i,0]);
		for j:=1 to y[i,0] do begin
			read(y[i,j]);
		end;
	end;
	for i:=1 to k do begin
		for j:=1 to n do begin
			dfs(i,j);
		end;
	end;
	for i:=1 to n do begin
		for j:=1 to k do if x[i,j]<x[i,-1] then begin
			for l:=x[i,j] to v do begin
				for r:=j to k do begin
					if z[l,r]<z[l-x[i,j],r-j]+x[i,-1]-x[i,j] then z[l,r]:=z[l-x[i,j],r-j]+x[i,-1]-x[i,j];
				end;
			end;
		end;
	end;
	writeln(z[v,k]);
	close(output);
end.
