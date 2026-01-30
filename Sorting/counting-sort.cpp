#include<iostream>
#include<vector>
#include<limits>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    vector<int>farr(max+1,0);
    for(int i=0;i<n;i++){
        farr[arr[i]]++;
    }
    int s=0;
    vector<int>cumarr(max+1,0);
    for(int i=0;i<max+1;i++){
        s=s+farr[i];
        cumarr[i]=s;
    }

    vector<int>sortarr(n);
    for(int i=0;i<n;i++){
        cumarr[arr[n-1-i]]--;
        sortarr[cumarr[arr[n-1-i]]]=arr[n-1-i];
    }


    for(int i=0;i<n;i++){
        cout<<sortarr[i]<<" ";
    }
}