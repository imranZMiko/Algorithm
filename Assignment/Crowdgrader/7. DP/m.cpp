#include<bits/stdc++.h>
using namespace std;

struct state {
    int i, j, k;
    state() {};
    state(int _i, int _j, int _k) {
        i = _i;
        j = _j;
        k = _k;
    }
};

int arr1[110], arr2[110];
int dp[110][110][110];
state parent[110][110][110];

int solve(int l1, int l2, int idx) {
    if(l1 == 0 or l2 == 0) {
        parent[l1][l2][idx] = state(-1, -1, -1);
        return 0;
    }

    if(dp[l1][l2][idx] != -1)
        return dp[l1][l2][idx];

    int a = -1, b = -1, c = -1;
    if(arr1[l1-1] == arr2[l2-1] and arr2[l2-1] < arr2[idx])
        a = 1 + solve(l1-1, l2-1, l2-1);
    b = solve(l1, l2-1, idx);
    c = solve(l1-1, l2, idx);

    if(a>b and a>c) {
        parent[l1][l2][idx] = state(l1-1, l2-1, l2-1);
        dp[l1][l2][idx] = a;
    }

    else if(b>a and b>c) {
        parent[l1][l2][idx] = state(l1, l2-1, idx);
        dp[l1][l2][idx] = b;
    }

    else {
        parent[l1][l2][idx] = state(l1-1, l2, idx);
        dp[l1][l2][idx] = c;
    }

    return dp[l1][l2][idx];
}

int main() {
    int l1, l2;
    cin >> l1 >> l2;

    for(int i=0; i<l1; i++)
        cin >> arr1[i];
    for(int i=0; i<l2; i++)
        cin >> arr2[i];

    arr2[l2] = INT_MAX;
    memset(dp, -1, sizeof dp);
    solve(l1, l2, l2);

    stack<int> LCIS;
    int i = l1, j = l2, k = l2;
    while(parent[i][j][k].i != -1) {
        state p = parent[i][j][k];
        if(p.i == i-1 and p.j == j-1)
            LCIS.push(arr1[i-1]);
        i = p.i;
        j = p.j;
        k = p.k;
    }

    while(not LCIS.empty()) {
        cout << LCIS.top() << endl;
        LCIS.pop();
    }
}