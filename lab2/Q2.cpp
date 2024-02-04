#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int j = m;
    while (j < n)
    {
        int k = a[j];
        int i = j - 1;
        for (; i >= 0; i--)
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

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}