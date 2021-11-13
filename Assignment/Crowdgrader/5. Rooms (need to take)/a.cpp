/*
You are given N activities. Each activity has a start time and a finish time. You need a classroom to hold each activity. Two activities can't be scheduled in the same classroom if they overlap. What is the minimum number of classrooms you will need to hold all the activities?

Input
First line: N(0<N≤105), number of activities. Next N lines, each: LR(0≤L<R<109), where L is the starting time and R is the finishing time of ith activity.

Output
Output the minimum number of classrooms you will need. See sample for clarification.

Sample
Input
-----
6
0 100
1 10
10 20
5 15
17 25
21 30

Output
------
3
*/

#include<bits/stdc++.h>
using namespace std;

struct time_pair
{
    int L;
    int R;
    time_pair();
    time_pair(int _L,int _R)
    {
        L=_L; R=_R;
    }
    bool operator<(const time_pair &a)const
    {
        return R<a.R;
    }

};

vector<time_pair>times;
int n,rooms;

void input()
{
    int l,r;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&l,&r);
        times.push_back(time_pair(l,r));
    }
    sort(times.begin(),times.end());
}

void room_count()
{
    int i,min=0,finish,start;
    rooms=1;
    for(i=0;i<n-1;i++)
    {
        finish=times[min].R;    //current minimum finishing time
        start=times[i+1].L;     //starting time of the next pair

        if(finish<=start)       //if they don't overlap
            min++;              //the next minimum is set as the minimum
        else                    //if they overlap
            rooms++;            //room count is increased
    }
}

void output()
{
    printf("%d\n",rooms);
}

int main()
{
    input();
    room_count();
    output();
    return 0;
}