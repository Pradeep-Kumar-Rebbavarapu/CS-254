#include <iostream>
#include <vector>
using namespace std;

void __merge__sorted__arrays__and__get__union__(vector<int> &arr1,vector<int> &arr2,int n,int m,vector<int> &arr3){
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    while(i<n)
        arr3[k++] = arr1[i++];
    while(j<m)
        arr3[k++] = arr2[j++];
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    vector<int> arr3(m+n);
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    __merge__sorted__arrays__and__get__union__(arr1,arr2,n,m,arr3);
    for(auto i:arr3){
        cout<<i<<" ";
    }
}




