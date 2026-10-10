#include <iostream>
using namespace std;
int main(){
    int n1,n2;
    cout << "Enter size of Array 1"<< endl;
    cin >> n1;
    int arr1[n1];
cout  << "Enter the elements of Array1" << endl;
for(int i=0;i<n1;i++){
    cin >> arr1[i];
}
cout << "Enter size of Array 2"<< endl; 
    cin >>n2;
    int arr2[n2];
cout  << "Enter the elements of Array2" << endl;
for(int i=0;i<n2;i++){
    cin >> arr2[i];
}
int res[n1+n2];
for(int i=0;i<n1;i++){
    res[i]=arr1[i];
}
for(int i=0;i<n2;i++){
    res[n1+i]=arr2[i];
}
for(int i=0;i<n1+n2;i++){
    cout << res[i] << " ";
}
return 0;
}