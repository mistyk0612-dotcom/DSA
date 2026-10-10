#include <iostream>
using namespace std;

int binarysearch(int [],int,int);
int main(){
    int size;
    cout << "Enter the size of the Array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of Array: ";
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }
    int key;
    cout << "Enter the value to be searched: ";
    cin >> key;
    int res = binarysearch(arr, size , key);
    if (res==-1){
        cout << "Element is not present!";
    }
    else cout << "Element found at index: " << res;
    return 0;
}
int binarysearch(int arr[],int n,int key){
    int lb=0;
    int ub=n-1; 
    while (lb<=ub){ 
    int mid = (lb+ub)/2;
    if (key ==arr[mid]){
        return mid;
    }
    else if(key>arr[mid]){
        lb=mid+1;
    }
    else{ 
        ub = mid - 1;
}
    }
    return -1;
}

