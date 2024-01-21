#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("test_cases_Q5.txt", "r", stdin);
    freopen("output_Q5.txt", "w", stdout);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int sizeArray;
        cin >> sizeArray;
        vector<int> inputArray(sizeArray);

        for (int i = 0; i < sizeArray; i++)
            cin >> inputArray[i];

        int firstMin = INT_MAX, secondMin = INT_MAX;
        
        for (int i = 0; i < sizeArray; i++) {
            if (inputArray[i] <= firstMin) {
                secondMin = firstMin;
                firstMin = inputArray[i];
            } else if (inputArray[i] < secondMin) {
                secondMin = inputArray[i];
            }
        }

        cout << "First minimum: " << firstMin << " and second minimum: " << secondMin << endl;
        // The complexity of the following algorithm is O(n)
    }

    return 0;
}
