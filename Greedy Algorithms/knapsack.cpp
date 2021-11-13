/*
Algorithm fractionalKnapsack(S, W)

Input: set S of items w/ benefit bi and weight wi; max. weight W

Output: amount xi of each item i to maximize benefit w/ weight at most W

for each item i in S
	xi ← 0
	vi ← bi / wi 		{value}
w ← 0 					{total weight}
while w < W
	remove item i with highest vi
	xi ← min{wi , W - w}
	w ← w + min{wi , W - w}
*/