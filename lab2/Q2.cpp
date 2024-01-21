#include <bits/stdc++.h>
using namespace std;

int nextGap(int gap) {
    if (gap <= 1)
        return 0;
    return ceil(gap / 2.0);
}

// O(n log(n)) solution
void shellSort(vector<int> &arr, int m) {
    int n = arr.size();
    if (m == 0 || m == n)
        return;
    for (int currentGap = nextGap(n); currentGap > 0; currentGap = nextGap(currentGap)) {
        for (int i = 0; i + currentGap < n; i++) {
            int j = i + currentGap;
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

// O(n) solution for large range [1, 10^9]
void largeRangeSort(vector<long long> &arr, int m) {
    int n = arr.size();
    int indexI = 0, indexJ = m, indexK = 0;
    long long modValue = 10000000000;
    while (indexK < n) {
        if (indexJ == n || (arr[indexI] % modValue) < (arr[indexJ] % modValue)) {
            arr[indexK] += modValue * (arr[indexI] % modValue);
            indexI++;
            indexK++;
        } else if (indexI == m || (arr[indexI] % modValue) >= (arr[indexJ] % modValue)) {
            arr[indexK] += modValue * (arr[indexJ] % modValue);
            indexJ++;
            indexK++;
        }
    }
    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] / modValue);
}

int main() {
    freopen("test_cases_Q2.txt", "r", stdin);
    freopen("output_Q2.txt", "w", stdout);
    
    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        int sizeArray, m;
        cin >> sizeArray >> m;
        
        vector<int> originalArray(sizeArray);
        for (int i = 0; i < sizeArray; i++)
            cin >> originalArray[i];
        
        shellSort(originalArray, m);
        
        cout << "Sorted Array: ";
        for (auto element : originalArray)
            cout << element << " ";
        cout << endl;
    }

    return 0;
}
