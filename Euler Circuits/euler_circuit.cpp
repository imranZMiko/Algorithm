/*
Algorithm for Euler Circuits

Choose a root vertex r and start with the trivial partial circuit (r).

Given a partial circuit (r = x0,x1,…,xt = r) that traverses some but not all of the edges of G containing r, remove these edges from G. Let i be the least integer for which xi is incident with one of the remaining edges. Form a greedy partial circuit among the remaining edges of the form (xi = y0,y1,…,ys = xi).

Expand the original circuit:
r =(x0,x1,…, xi-1, xi = y0,y1,…,ys = xi, xi+1,…, xt=r)

procedure FindEulerPath(V)
  1. iterate through all the edges outgoing from vertex V;
       remove this edge from the graph,
       and call FindEulerPath from the second end of this edge;
  2. add vertex V to the answer.

stack St;
put start vertex in St;
until St is empty
  let V be the value at the top of St;
  if degree(V) = 0, then
    add V to the answer;
    remove V from the top of St;
  otherwise
    find any edge coming out of V;
    remove it from the graph;
    put the second end of this edge in St;
*/