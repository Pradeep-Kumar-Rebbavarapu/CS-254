#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    vector<int> merged(m + n);

    int i = 0, j = 0, k = 0;

    // Merge the two sorted arrays
    while (i < m && j < n) {
        if (nums1[i] <= nums2[j]) {
            merged[k++] = nums1[i++];
        } else {
            merged[k++] = nums2[j++];
        }
    }

    // Copy the remaining elements from nums1, if any
    while (i < m) {
        merged[k++] = nums1[i++];
    }

    // Copy the remaining elements from nums2, if any
    while (j < n) {
        merged[k++] = nums2[j++];
    }

    // Calculate the median based on the size of the merged array
    if ((m + n) % 2 == 0) {
        // If the total number of elements is even, return the average of the middle two elements
        return (double)(merged[(m + n) / 2 - 1] + merged[(m + n) / 2]) / 2.0;
    } else {
        // If the total number of elements is odd, return the middle element
        return (double)merged[(m + n) / 2];
    }
}

int main() {
    // Example usage
    int n,m;
    cin>>n>>m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }

    double median = findMedianSortedArrays(nums1, nums2);

    cout << "Median of the two sorted arrays: " << median << endl;

    return 0;
}
