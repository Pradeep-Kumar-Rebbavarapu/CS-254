#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>> &matrix, int row, int col, int __total_rows, int __total_columns)
{
    if (row < 0 || col < 0 || row >= __total_rows || col >= __total_columns || matrix[row][col] == 0)
    {
        return 0;
    }

    matrix[row][col] = 0;
    int size = 1;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            size += dfs(matrix, row + i, col + j, __total_rows, __total_columns);
        }
    }

    return size;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int max_cells = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (matrix[row][col] == 1)
            {
                max_cells = max(max_cells, dfs(matrix, row, col, n, n));
            }
        }
    }

    cout << max_cells << endl;
    return 0;
}
