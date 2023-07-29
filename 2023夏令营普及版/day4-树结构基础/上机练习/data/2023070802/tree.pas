var   root:array[0..1000000] of boolean;
      l,r:array[0..1000000] of longint;
      n,i,g,u,v,t:longint;
procedure dfs(t:longint);
      begin
            if l[t]<>0 then dfs(l[t]);
            write(t,' ');
            if r[t]<>0 then dfs(r[t]);
      end;
procedure bfs(t:longint);
      begin
            write(t,' ');
            if l[t]<>0 then bfs(l[t]);
            if r[t]<>0 then bfs(r[t]);
      end;
begin
      assign(input,'tree.in'); reset(input);
      assign(output,'tree.out');rewrite(output);
      readln(n);
      fillchar(root,sizeof(root),1);
      for i:=1 to n do
      begin
            readln(u,v);
            if u=0 then continue;
            root[v]:=false;
            if l[u]=0 then l[u]:=v
            else
            begin
                  t:=l[u];
                  while r[t]<>0 do t:=r[t];
                  r[t]:=v;
            end;
      end;
      for i:=1 to n do
         if root[i] then g:=i;
      bfs(g);
      writeln;
      dfs(g);
      close(input);
      close(output);
end.
