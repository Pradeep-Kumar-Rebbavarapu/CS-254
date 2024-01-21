#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int left, int right) {
    int pivot = arr[right], partitionIndex = left;
    for (int i = left; i <= right; i++) {
        if (arr[i] < pivot)
            swap(arr[i], arr[partitionIndex++]);
    }
    swap(arr[right], arr[partitionIndex]);
    return partitionIndex;
}

int randomPartition(vector<int> &arr, int left, int right) {
    int size = right - left + 1;
    int pivotIndex = (rand() % size);
    swap(arr[left + pivotIndex], arr[right]);
    return partition(arr, left, right);
}

void findMedian(vector<int> &arr, int left, int right, int k, int &median1, int &median2) {
    if (left > right)
        return;
    int partitionIndex = randomPartition(arr, left, right);
    if (partitionIndex == k) {
        median2 = arr[partitionIndex];
        if (median1 != -1)
            return;
    } else if (partitionIndex == k - 1) {
        median1 = arr[partitionIndex];
        if (median2 != -1)
            return;
    }
    if (partitionIndex >= k)
        findMedian(arr, left, partitionIndex - 1, k, median1, median2);
    else
        findMedian(arr, partitionIndex + 1, right, k, median1, median2);
}

void calculateAndPrintMedian(vector<int> &arr) {
    int median1 = -1, median2 = -1, size = arr.size();
    int k = size / 2;
    findMedian(arr, 0, size - 1, k, median1, median2);
    if (size % 2)
        cout << "Median: " << median2 << endl;
    else
        cout << "Median: " << (median1 + median2) / 2.0 << endl;
}

int main() {
    freopen("test_cases_Q4.txt", "r", stdin);
    freopen("output_Q4.txt", "w", stdout);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int sizeArray;
        cin >> sizeArray;
        vector<int> inputArray(sizeArray);

        for (int i = 0; i < sizeArray; i++)
            cin >> inputArray[i];

        calculateAndPrintMedian(inputArray);
    }

    return 0;
}
