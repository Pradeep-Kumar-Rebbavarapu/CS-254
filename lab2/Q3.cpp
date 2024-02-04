#include <bits/stdc++.h>
using namespace std;
void merge(int i1, int i2, int j1, int j2, int a[])
{
    int j = j1;
    while (j <= j2)
    {
        int k = a[j];
        int i = j - 1;
        for (; i >= i1; i--)
        {
            if (a[i] > k)
            {
                a[i + 1] = a[i];
            }
            else
            {
                break;
            }
        }
        a[i + 1] = k;
        j++;
    }
}
void partition(int i, int j, int a[])
{
    if (i == j)
    {
        return;
    }
    int mid = (i + j) / 2;
    partition(i, mid, a);
    partition(mid + 1, j, a);
    merge(i, mid, mid + 1, j, a);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    partition(0, n - 1, a);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}