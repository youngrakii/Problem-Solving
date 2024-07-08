#include <iostream>
using namespace std;
int main(){
    int student=0;
    int apple=0;
    int n=0;
    int sum=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>student>>apple;
        sum+=apple%student;
    }
    cout<<sum<<endl;
}