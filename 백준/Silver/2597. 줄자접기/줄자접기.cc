#include <bits/stdc++.h>

using namespace std;

pair<double, double> arr[3];

double update(double mid, double num){
    return mid + fabs(mid-num);
}

void func(int idx, double& l, double& r){
    if(arr[idx].first == arr[idx].second){
        return;
    }
    
    double mid = (arr[idx].first + arr[idx].second)/2;
    
    for(int i= idx+1; i<3; i++){
        arr[i].first = update(mid, arr[i].first);
        arr[i].second = update(mid, arr[i].second);
    }
    
    l = update(mid, l);
    if(l>r){
        r=l;
    }
    l=mid;
}

int main(void){
    double len;
    cin>>len;
    
    double left = 0, right =len;
    
    for(int i=0; i<3; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    
    for(int i=0; i<3; i++){
        func(i, left, right);
    }
    
    double res = right - left;
    res*=10;
    res=floor(res);
    res/=10;
    cout<<fixed;
    cout.precision(1);
    cout<<res;
    return 0;
}