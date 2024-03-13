#include <iostream>
using namespace std;

int main(){
    int sum=0;
    int arr[5]={0,};
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    for(int i=0;i<5;i++){
        arr[i]=arr[i]*arr[i];
        sum+=arr[i];
    }
    cout<<sum%10;
    return 0;
}