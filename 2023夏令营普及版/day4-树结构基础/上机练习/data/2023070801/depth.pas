type data=record
     left,right,dep:longint;
     end;
var  a:array[1..1000000]of data;
     n,i,x,y,max:longint;

procedure work(kk:longint);
begin
if a[kk].left<>0 then
  begin
  a[a[kk].left].dep:=a[kk].dep+1;
  work(a[kk].left);
  end;
if a[kk].right<>0 then
  begin
  a[a[kk].right].dep:=a[kk].dep+1;
  work(a[kk].right);
  end;
end;

begin
assign(input,'depth.in');reset(input);
assign(output,'depth.out');rewrite(output);

readln(n);

for i:=1 to n do
  begin
  readln(x,y);
  a[i].left:=x;
  a[i].right:=y;
  end;
a[1].dep:=1;
work(1);

max:=0;
for i:=1 to n do if a[i].dep>max then max:=a[i].dep;
writeln(max);

close(input);close(output);
end.
