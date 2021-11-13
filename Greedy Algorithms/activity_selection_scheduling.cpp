/*
Greedy-Activity-Selector(s, f)
	n <− length[s]
	A <− {1}					{Automatically select first activity}
	j <− 1						{Last activity selected so far}
	for i <− 2 to n do
		if si >= fj then
			A <− A U {i}		{Add activity i to the set}
			j <− i 				{record last activity added}
	return A
*/