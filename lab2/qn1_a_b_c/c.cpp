#include <iostream>
#include <vector>
using namespace std;

void __get__intersection__of__sorted__arrays__(vector<int> &arr1,vector<int> &arr2,int n,int m,vector<int> &arr3){
    int i=0,j=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr1[i]>arr2[j]){
            j++;
        } 
        else{
            arr3.push_back(arr1[i++]);
            j++;
        }
            
    }
}


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    vector<int> arr3;
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    __get__intersection__of__sorted__arrays__(arr1,arr2,n,m,arr3);
    for(auto i:arr3){
        cout<<i<<" ";
    }
}