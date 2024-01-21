#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeArrays(vector<int> &firstArray, vector<int> &secondArray) {
    int sizeFirst = firstArray.size(), sizeSecond = secondArray.size();
    vector<int> mergedArray(sizeFirst + sizeSecond);
    int indexFirst = 0, indexSecond = 0, indexMerged = 0;

    while (indexMerged < sizeFirst + sizeSecond) {
        if (indexSecond == sizeSecond || firstArray[indexFirst] <= secondArray[indexSecond])
            mergedArray[indexMerged++] = firstArray[indexFirst++];
        if (indexFirst == sizeFirst || firstArray[indexFirst] > secondArray[indexSecond])
            mergedArray[indexMerged++] = secondArray[indexSecond++];
    }

    return mergedArray;
}

vector<int> findUnion(vector<int> &firstArray, vector<int> &secondArray) {
    int sizeFirst = firstArray.size(), sizeSecond = secondArray.size();
    vector<int> unionArray;
    int indexFirst = 0, indexSecond = 0;

    while (indexFirst < sizeFirst && indexSecond < sizeSecond) {
        if (unionArray.size() > 0 && unionArray.back() == firstArray[indexFirst])
            indexFirst++;
        else if (unionArray.size() > 0 && unionArray.back() == secondArray[indexSecond])
            indexSecond++;
        else if (firstArray[indexFirst] <= secondArray[indexSecond])
            unionArray.push_back(firstArray[indexFirst++]);
        else if (firstArray[indexFirst] > secondArray[indexSecond])
            unionArray.push_back(secondArray[indexSecond++]);
    }

    while (indexFirst < sizeFirst) {
        if (unionArray.back() != firstArray[indexFirst])
            unionArray.push_back(firstArray[indexFirst]);
        indexFirst++;
    }

    while (indexSecond < sizeSecond) {
        if (unionArray.back() != secondArray[indexSecond])
            unionArray.push_back(secondArray[indexSecond]);
        indexSecond++;
    }

    return unionArray;
}

vector<int> findIntersection(vector<int> &firstArray, vector<int> &secondArray) {
    int sizeFirst = firstArray.size(), sizeSecond = secondArray.size();
    vector<int> intersectionArray;
    int indexFirst = 0, indexSecond = 0;

    while (indexFirst < sizeFirst && indexSecond < sizeSecond) {
        if (firstArray[indexFirst] < secondArray[indexSecond])
            indexFirst++;
        else if (firstArray[indexFirst] > secondArray[indexSecond])
            indexSecond++;
        else {
            if (!intersectionArray.size() || intersectionArray.back() != firstArray[indexFirst])
                intersectionArray.push_back(firstArray[indexFirst]);
            indexFirst++;
            indexSecond++;
        }
    }

    return intersectionArray;
}

int main() {
    freopen("test_cases_Q1.txt", "r", stdin);
    freopen("output_Q1.txt", "w", stdout);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int sizeFirstArray, sizeSecondArray;
        cin >> sizeFirstArray >> sizeSecondArray;

        vector<int> firstArray(sizeFirstArray), secondArray(sizeSecondArray);

        for (int i = 0; i < sizeFirstArray; i++)
            cin >> firstArray[i];

        for (int j = 0; j < sizeSecondArray; j++)
            cin >> secondArray[j];

        vector<int> mergedArray = mergeArrays(firstArray, secondArray);
        vector<int> intersectionArray = findIntersection(firstArray, secondArray);
        vector<int> unionArray = findUnion(firstArray, secondArray);

        cout << "Merged Array: ";
        for (auto element : mergedArray)
            cout << element << " ";
        cout << endl;

        cout << "Intersection Array: ";
        for (auto element : intersectionArray)
            cout << element << " ";
        cout << endl;

        cout << "Union Array: ";
        for (auto element : unionArray)
            cout << element << " ";
        cout << endl;
    }

    return 0;
}
