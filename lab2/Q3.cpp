#include <bits/stdc++.h>
using namespace std;

int nextGap(int gap) {
    if (gap <= 1)
        return 0;
    return ceil(gap / 2.0);
}

// O(n log(n)) merge
void combMerge(vector<int> &arr, int left, int right) {
    int size = arr.size();
    for (int currentGap = nextGap(right - left + 1); currentGap > 0; currentGap = nextGap(currentGap)) {
        for (int i = left; i + currentGap <= right; i++) {
            int j = i + currentGap;
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

// O(n * log(n) * log(n)) combSort
void combSort(vector<int> &arr, int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    combSort(arr, left, mid);
    combSort(arr, mid + 1, right);
    combMerge(arr, left, right);
}

void combSort(vector<int> &arr) {
    combSort(arr, 0, arr.size() - 1);
}

int main() {
    freopen("test_cases_Q3.txt", "r", stdin);
    freopen("output_Q3.txt", "w", stdout);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int sizeArray;
        cin >> sizeArray;

        vector<int> originalArray(sizeArray);
        for (int i = 0; i < sizeArray; i++)
            cin >> originalArray[i];

        combSort(originalArray);

        for (auto element : originalArray)
            cout << element << " ";
        cout << endl;
    }

    return 0;
}
