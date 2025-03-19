#include <iostream>
using namespace std;

int main() {
  int arr[100001], n, max=0, count=0;

  cin>>n;

  for(int i=0; i<n; i++)
      cin>>arr[i];

  for(int i=n-1; i>=0; i--)
  {
    if(max < arr[i])
    {
      count++;
      max=arr[i];
    }
  }

  cout<<count;

}