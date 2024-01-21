#include <bits/stdc++.h>
using namespace std;

int medianPartition(vector<int> &arr, int left, int right) {
    int pivotValue = arr[right], partitionIndex = left;
    for (int i = left; i <= right; i++) {
        if (arr[i] < pivotValue)
            swap(arr[i], arr[partitionIndex++]);
    }
    swap(arr[right], arr[partitionIndex]);
    return partitionIndex;
}

int randomPartition(vector<int> &arr, int left, int right) {
    int size = right - left + 1;
    int pivotIndex = (rand() % size);
    swap(arr[left + pivotIndex], arr[right]);
    return medianPartition(arr, left, right);
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

int findMedianValue(vector<int> arr) {
    int median1 = -1, median2 = -1, size = arr.size();
    int k = size / 2;
    findMedian(arr, 0, size - 1, k, median1, median2);
    return median2;
}

int medianPosition(vector<int> &arr, int left, int right) {
    if (left == right)
        return left;
    vector<int> subArray;
    for (int i = left; i <= right; i++)
        subArray.push_back(arr[i]);
    int medianValue = findMedianValue(subArray);
    for (int i = left; i <= right; i++)
        if (arr[i] == medianValue)
            return i;
}

int partition(vector<int> &arr, int left, int right) {
    int pivotIndex = medianPosition(arr, left, right);
    swap(arr[pivotIndex], arr[right]);
    int pivotValue = arr[right];
    int low = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue)
            swap(arr[i], arr[low++]);
    }
    swap(arr[low], arr[right]);
    return low;
}

void quickSort(vector<int> &arr, int left, int right) {
    if (left >= right)
        return;
    int pivotIndex = partition(arr, left, right);
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

int main() {
    freopen("test_cases_Q6.txt", "r", stdin);
    freopen("output_Q6.txt", "w", stdout);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int sizeArray;
        cin >> sizeArray;
        vector<int> inputArray(sizeArray);

        for (int i = 0; i < sizeArray; i++)
            cin >> inputArray[i];

        quickSort(inputArray, 0, sizeArray - 1);

        cout << "Sorted Array: ";
        for (auto element : inputArray)
            cout << element << " ";
        cout << endl;
    }

    return 0;
}
