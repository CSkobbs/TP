
DFS(G)
  for each vertex u in V 
    color[u] := WHITE
    p[u] = u 
  end for
  time := 0
  if there is a starting vertex s
    call DFS-VISIT(G, s)
  for each vertex u in V 
    if color[u] = WHITE
      call DFS-VISIT(G, u)
  end for
  return (p,d_time,f_time) 

DFS-VISIT(G, u) 
  color[u] := GRAY
  d_time[u] := time := time + 1 
  for each v in Adj[u] 
    if (color[v] = WHITE)
      p[v] = u 
      call DFS-VISIT(G, v)
    else if (color[v] = GRAY) 
      ...
    else if (color[v] = BLACK) 
      ...
  end for
  color[u] := BLACK
  f_time[u] := time := time + 1 
-
-
initialize vertex u
-
-
-
-
start vertex s
-
-
start vertex u
-
-
-
-
discover vertex u
-
examine edge (u,v)
-
(u,v) is a tree edge
-
-
(u,v) is a back edge
-
(u,v) is a cross or forward edge
-
finish vertex u
-