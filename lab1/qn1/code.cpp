#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int __get__max__(vector<int> &arr){
    int max_ele = INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>max_ele){
            max_ele = arr[i];
        }
    }
    return max_ele;
}

int __get__second__max__ele__(vector<int> &arr,int max_ele){
    int second_max_ele = INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>second_max_ele & arr[i]<max_ele){
            second_max_ele = arr[i];
        }
    }
    return second_max_ele
}

int main() {
    freopen("input.txt", "r", stdin);
    vector<int> arr;
    long long max_ele = __get__max__(arr);
    long long second_max_ele = __get__second__max__ele__(arr,max_ele);
    freopen("output.txt", "w", stdout); 

    return 0;
}
