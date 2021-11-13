/*
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

// FEP(1)
//   1-3
//   FEP(3)
//   	3-4
//   	FEP(4)
//   	  4-2
//   	  FEP(2)
//   	    2-1
//   	      FEP(1)
//   	      	Add 1 to answer
//   	    2-5
//   	      FEP(5)
//   	        5-8
//   	        FEP(8)
//   	          8-2
//   	          FEP(2)
//   	          Add 2 to answer
//   	        Add 8 to answer
//   	      Add 5 to answer
//   	    2-8
//   	  Add 2 to answer
//   	Add 4 to answer
//   Add 3 to answer
//   1-2
// Add 1 to answer
// 1-2-8-5-2-4-3-1