#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mod 1000000007

void MIN(int *arr1, int *arr2, int *arr3, vector<int> &sortedarray, int n, int inc, int *pti,
         int *ptj, int *ptk, int K, int *ptcount)
{   
    if (arr1[min((*pti + inc), n)] >= arr2[min((*ptj + inc), n)] && arr2[min((*ptj + inc), n)] <= arr3[min(n, *ptk + inc)] && (*ptj) < n)
    {
        for (int i = 1; i <= inc; i++)
        {
            if (i + (*ptj) > n)
                break;
            sortedarray.pb(arr2[*ptj + i]);
            (*ptcount)++;
        }
        (*ptj) = min(n, (*ptj) + inc);
    }

    else if (arr1[min((*pti + inc), n)] <= arr2[min((*ptj + inc), n)] && arr1[min((*pti + inc), n)] <= arr3[min(n, *ptk + inc)] && (*pti) < n)
    {
        for (int i = 1; i <= inc; i++)
        {
            if ((*pti) + i > n)
                break;
            sortedarray.pb(arr1[*pti + i]);
            (*ptcount)++;
        }
        (*pti) = min(n, (*pti) + inc);
    }

    else if (arr3[min((*ptk + inc), n)] <= arr2[min((*ptj + inc), n)] && arr1[min((*pti + inc), n)] >= arr3[min(n, *ptk + inc)] && (*ptk) < n)
    {   
        for (int i = 1; i <= inc; i++)
        {
            if ((*ptk) + i > n)
                break;
            sortedarray.pb(arr3[*ptk + i]);
            (*ptcount)++;
        }
        (*ptk) = min(n, (*ptk) + inc);
    }
    // condition when one array is exhausted
    // arr1 exhausted
    else if ((*pti) == n)
    {
        if (arr2[min((*ptj + inc), n)] <= arr3[min(n, *ptk + inc)])
        {   
            for (int i = 1; i <= inc; i++)
            {
                if (i + (*ptj) > n)
                    break;
                sortedarray.pb(arr2[*ptj + i]);
                (*ptcount)++;
            }
            (*ptj) = min(n, (*ptj) + inc);
        }
        else
        {   
            for (int i = 1; i <= inc; i++)
            {
                if ((*ptk) + i > n)
                    break;
                sortedarray.pb(arr3[*ptk + i]);
                (*ptcount)++;
            }
            (*ptk) = min(n, (*ptk) + inc);
        }
    }
    //arr2 exhausted
    else if ((*ptj) == n)
{
    if (arr1[min((*pti + inc), n)] <= arr3[min(n, *ptk + inc)])
    {   
        for (int i = 1; i <= inc; i++)
        {
            if (i + (*pti) > n)
                break;
            sortedarray.pb(arr1[*pti + i]);
            (*ptcount)++;
        }
        (*pti) = min(n, (*pti) + inc);
    }
    else
    {   
        for (int i = 1; i <= inc; i++)
        {
            if ((*ptk) + i > n)
                break;
            sortedarray.pb(arr3[*ptk + i]);
            (*ptcount)++;
        }
        (*ptk) = min(n, (*ptk) + inc);
    }
}
//arr3 exhausted 
else if ((*ptk) == n)
{   
    if (arr2[min((*ptj + inc), n)] <= arr1[min(n, *pti + inc)])
    {
        for (int i = 1; i <= inc; i++)
        {
            if (i + (*ptj) > n)
                break;
            sortedarray.pb(arr2[*ptj + i]);
            (*ptcount)++;
        }
        (*ptj) = min(n, (*ptj) + inc);
    }
    else
    {   
        for (int i = 1; i <= inc; i++)
        {
            if ((*pti) + i > n)
                break;
            sortedarray.pb(arr1[*pti + i]);
            (*ptcount)++;
        }
        (*pti) = min(n, (*pti) + inc);
    }
}

    // condition when two arrays have been exhauste
    else if ((*pti) < n && (*ptj) == n && (*ptk) == n)
    {
        for (int i = 1; i <= inc; i++)
        {
            if ((*pti) + i > n)
                break;
            sortedarray.pb(arr1[*pti + i]);
            (*ptcount)++;
        }
        (*pti) = min(n, (*pti) + inc);
    }
    else if ((*pti) == n && (*ptj) < n && (*ptk) == n)
    {
        for (int i = 1; i <= inc; i++)
        {
            if ((*ptj) + i > n)
                break;
            sortedarray.pb(arr1[*ptj + i]);
            (*ptcount)++;
        }
        (*ptj) = min(n, (*ptj) + inc);
    }
    else if ((*pti) == n && (*ptj) == n && (*ptk) < n)
    {
        for (int i = 1; i <= inc; i++)
        {
            if ((*ptk) + i > n)
                break;
            sortedarray.pb(arr1[*ptk + i]);
            (*ptcount)++;
        }
        (*ptk) = min(n, (*ptk) + inc);
    }

}

void solve(int *arr1, int *arr2, int *arr3, int n, int K)
{
    int i = 0, j = 0, k = 0;

    vector<int> sortedarray;

    int *pt_i = &i, *pt_j = &j, *pt_k = &k;
    int counter = 0;
    int *ptCount = &counter;

    MIN(arr1, arr2, arr3, sortedarray, n, K / 3, pt_i, pt_j, pt_k, K, ptCount);

    MIN(arr1, arr2, arr3, sortedarray, n, K / 3, pt_i, pt_j, pt_k, K, ptCount);

    while (counter < K)
    {
        int I = (K - counter) / 2;
        if (I == 0)
            I = 1;
        MIN(arr1, arr2, arr3, sortedarray, n, I, pt_i, pt_j, pt_k, K, ptCount);
    }
    int fin = sortedarray[sortedarray.size() - 1];
    cout << fin << "\n";
}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test = 1;
    cin >> test;
    while (test--)
    {
        int n, k;
        cin >> n >> k;
        int arr1[n + 1], arr2[n + 1], arr3[n + 1];
        for (int i = 0; i <= n; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i <= n; i++)
        {
            cin >> arr2[i];
        }
        for (int i = 0; i <= n; i++)
        {
            cin >> arr3[i];
        }
        solve(arr1, arr2, arr3, n, k);
    }
    return 0;
}
