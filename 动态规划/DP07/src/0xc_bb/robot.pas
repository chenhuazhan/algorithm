const
u:array[1..4,1..2]of longint=((1,0),(0,1),(-1,0),(0,-1));
v:array[0..5]of longint=(4,1,2,3,4,1);
var
x:array[0..101,0..101]of char;
y:array[0..100,0..100,1..4]of longint;
n,m,x0,y0,i,j,k,t,max,a:longint;
s:string;

begin
	assign(input,'robot.in');reset(input);
	assign(output,'robot.out');rewrite(output);
	readln(n,m,x0,y0);
	y[x0,y0,3]:=1;
	for i:=1 to n do begin
		for j:=1 to n do begin
			read(x[i,j]);
		end;
		readln;
	end;
	for t:=1 to m do begin
		readln(s);
		if s='FORWARD' then begin
			for i:=1 to n do begin
				for j:=1 to n do if x[i,j]='.'then begin
					for k:=3 to 4 do if y[i,j,k]>0 then begin
						if x[i+u[k,1],j+u[k,2]]='.' then begin
							if y[i+u[k,1],j+u[k,2],k]<=y[i,j,k] then
								y[i+u[k,1],j+u[k,2],k]:=y[i,j,k]+1;
						end;
					end;
				end;
			end;
			for i:=n downto 1 do begin
				for j:=n downto 1 do if x[i,j]='.'then begin
					for k:=1 to 2 do if y[i,j,k]>0 then begin
						if x[i+u[k,1],j+u[k,2]]='.' then begin
							if y[i+u[k,1],j+u[k,2],k]<=y[i,j,k] then
								y[i+u[k,1],j+u[k,2],k]:=y[i,j,k]+1;
						end;
					end;
				end;
			end;
		end;
		if s='BACK' then begin
			for i:=1 to n do begin
				for j:=1 to n do if x[i,j]='.'then begin
					for k:=1 to 2 do if y[i,j,k]>0 then begin
						if x[i-u[k,1],j-u[k,2]]='.' then begin
							if y[i-u[k,1],j-u[k,2],k]<=y[i,j,k] then
								y[i-u[k,1],j-u[k,2],k]:=y[i,j,k]+1;
						end;
					end;
				end;
			end;
			for i:=n downto 1 do begin
				for j:=n downto 1 do if x[i,j]='.'then begin
					for k:=3 to 4 do if y[i,j,k]>0 then begin
						if x[i-u[k,1],j-u[k,2]]='.' then begin
							if y[i-u[k,1],j-u[k,2],k]<=y[i,j,k] then
								y[i-u[k,1],j-u[k,2],k]:=y[i,j,k]+1;
						end;
					end;
				end;
			end;
		end;
		if (s='LEFT')or(s='RIGHT') then begin
			if s='RIGHT' then a:=1
			else a:=-1;
			for i:=1 to n do begin
				for j:=1 to n do if x[i,j]='.'then begin
					y[0,0]:=y[i,j];
					for k:=1 to 4 do if y[0,0,k]>0 then begin
						if y[i,j,v[k-a]]<=y[0,0,k] then
							y[i,j,v[k-a]]:=y[0,0,k]+1;
					end;
				end;
			end;
		end;
	end;
	for i:=1 to n do begin
		for j:=1 to n do begin
			for k:=1 to 4 do begin
				if max<y[i,j,k] then max:=y[i,j,k];
			end;
		end;
	end;
	writeln(m-(max-1));
	close(output);
end.
