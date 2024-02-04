#include <bits/stdc++.h>
using namespace std;

// O(n + k*log(n)) k*log(n) for popping k elements and initializing takes O(n)
int pqMethod(vector<int>&arr,int k){
        priority_queue<int> pq(arr.begin(), arr.end());
        for(int i=0; i<k-1; i++)
            pq.pop();
            return pq.top();
}

int main() {
  int n,k;
  cin>>n>>k;
  vector<int> arr(n);
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
  cout << "K'th largest element is " << pqMethod(arr, k);

  return 0;
}