#include <iostream>
using namespace std;
int main(){
    int n1,n2;
    cout << "Enter size of Array 1"<< endl;
    cin >> n1;
    int arr1[n1];
cout  << "Enter the elements of Array 1" << endl;
for(int i=0;i<n1;i++){
    cin >> arr1[i];
}
cout << "Enter size of Array 2"<< endl; 
    cin >>n2;
    int arr2[n2];
cout  << "Enter the elements of Array 2" << endl;
for(int i=0;i<n2;i++){
    cin >> arr2[i];
}
int res[n1+n2];
int j=0 ;
for(int i=0;i<n1+n2;i++){
        if (arr1[i]%2==0 && i<n1){
            res[j]=arr1[i];
            j++;
        }
        else if (arr2[i-n1]%2==0 && i<n2){
            res[j]=arr2[i-n1];
            j++;
        }
    } 


for(int i=0;i<j;i++){
    cout << res[i] << " ";
}
return 0;
}
