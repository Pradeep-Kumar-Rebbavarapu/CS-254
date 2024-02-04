#include <iostream>
#include <vector>

using namespace std;

void merge_sorted_arrays(vector<int>& arr, int m) {
    int mid = m - 1;
    int i = 0, j = mid + 1, k = 0;

    vector<int> temp(mid + arr.size() - j + 1);

    while (i <= mid && j < arr.size()) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j < arr.size()) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = 0; i < temp.size(); i++) {
        arr[mid + 1 + i] = temp[i];
    }
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 2, 4, 6, 8};
    int m = 4;

    merge_sorted_arrays(arr, m);

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
