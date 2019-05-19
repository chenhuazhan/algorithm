var
x:array[1..10000]of longint;
y:array[0..20000]of longint;
i,j,l,n,a:longint;

begin
	assign(input,'game.in');reset(input);
	assign(output,'game.out');rewrite(output);
	
	for i:=2 to 20000 do begin
		for j:=1 to l do begin
			if i mod x[j]=0 then break;
		end;
		if (l=0) or(i mod x[j]<>0) then begin
			inc(l);
			x[l]:=i;
		end;
		for j:=1 to l do begin
			if y[i-x[j]]<=0 then begin
				if (y[i]>1-y[i-x[j]])or(y[i]<=0) then y[i]:=1-y[i-x[j]];
			end
			else if (y[i]<=0)and(y[i]>-y[i-x[j]]-1) then begin
				y[i]:=-y[i-x[j]]-1;
			end;
		end;
	end;
	readln(n);
	for i:=1 to n do begin
		readln(a);
		if y[a]>0 then writeln(y[a])
		else writeln(-1);
	end;
	close(output);
end.