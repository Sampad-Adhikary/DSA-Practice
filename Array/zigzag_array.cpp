#include <bits/stdc++.h>
using namespace std;
void zigZag(int arr[], int n) {
        // code here
        
        for(long int i=0;i<n;i++){
            if((i%2 == 0) && arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
            else if(i%2!=0 && arr[i]<arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
        
        
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    zigZag(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}