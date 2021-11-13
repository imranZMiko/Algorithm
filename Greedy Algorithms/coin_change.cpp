/*
Objective: Pay out a given sum S with the smallest number of coins
possible. *Not always possible with greedy choice*

while S > 0 do
	c := value of the largest coin no larger than S;
	num := S / c;
	pay out num coins of value c;
	S := S - num*c;
*/