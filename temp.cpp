#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;
const unsigned long long mod = (1 << 64);

int n, m, cnt;
char arr[100][100];
unsigned long long dp[(1 << 8) + 1][(1 << 8) + 1];

bool check(int type, int i, int j, int mask, int nxt)
{
    if (type == 0)
    {
        if (i < n - 1 && j < m && !(nxt & (1 << j)) && !(mask & (1 << j)))
            return true;
    }
    else if (type == 1)
    {
        if (i < n && j < m - 1 && !(mask & (1 << j)) && !(mask & (1 << (j + 1))))
            return true;
    }
    else if (type == 2)
    {
        if (i < n - 1 && j < m - 1 && !(nxt & (1 << j)) && !(mask & (1 << j)) && !(nxt & (1 << (j + 1))))
            return true;
    }
    else if (type == 3)
    {
        if (i < n - 1 && j < m - 1 && !(nxt & (1 << j)) && !(mask & (1 << j)) && !(mask & (1 << (j + 1))))
            return true;
    }
    else if (type == 4)
    {
        if (i < n - 1 && j > 0 && j < m && !(nxt & (1 << j)) && !(mask & (1 << j)) && !(nxt & (1 << (j - 1))))
            return true;
    }
    else
    {
        if (i < n - 1 && j > 0 && j < m - 1 && !(mask & (1 << j)) && !(mask & (1 << (j + 1))) && !(nxt & (1 << (j + 1))))
            return true;
    }
    
    return false;
}

pair<int, int> update(int type, int i, int j, int mask, int nxt)
{
    if (type == 0)
        return { nxt |= (1 << j), mask |= (1 << j) };
    else if (type == 1)
    {
        mask |= (1 << j);
        mask |= (1 << (j + 1));
        
        return { nxt, mask };
    }
    else if (type == 2)
    {
        nxt |= (1 << j);
        mask |= (1 << j);
        nxt |= (1 << (j + 1));
        
        return { nxt, mask };
    }
    else if (type == 3)
    {
        nxt |= (1 << j);
        mask |= (1 << j);
        mask |= (1 << (j + 1));
        
        return { nxt, mask };
    }
    else if (type == 4)
    {
        nxt |= (1 << j);
        mask |= (1 << j);
        nxt |= (1 << (j - 1));
        
        return { nxt, mask };
    }
    else
    {
        nxt |= (1 << (j + 1));
        mask |= (1 << j);
        mask |= (1 << (j + 1));
        
        return { nxt, mask };
    }
}

unsigned long long solve(int idx, int mask, int nxt, int cur)
{
    if (m <= n)
    {
        if (idx == n)
            return (cur ? 0 : 1);
        
        if (mask == (1 << m) - 1)
            return solve(idx + 1, nxt, 0, cur);
        
        if (dp[idx][mask] != -1)
            return dp[idx][mask];
        
        unsigned long long ret = 0;
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < 6; ++j)
            {
                if (check(j, idx, i, mask, nxt))
                {
                    pair<int, int> var = update(j, idx, i, mask, nxt);
                    ret += solve(idx, var.second, var.first, cur - 1);
                }
            }
        }
        
        
    }
    else
    {
        
    }
}

int main()
{
    int test, cs = 1;
    scanf("%d", &test);
    
    while (test--)
    {
        memset(dp, -1, sizeof(dp));
        
        scanf("%d %d", &n, &m);
        
        
    }
    
    return 0;
}
