#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>> pq;

int solution(int a){
    int res=0;
    //갖고 있는 것들 중에 가장 큰 수(top) 출력하고 제거
    if(a==0){
        //없으면 -1
        if(pq.empty()){
            res=-1;
        }
        else{
            res=pq.top();
            pq.pop();
        }
    }else{//a개의 선물을 pq에 큰 것부터 저장
        for(int i=0; i<a; i++){
            int gift;
            cin>>gift;
            pq.push(gift);
        }
        res=-2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int a;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        int res = solution(a);
        if(res!=-2){
            cout<<res<<"\n";
        }
    }
    
    return 0;
}