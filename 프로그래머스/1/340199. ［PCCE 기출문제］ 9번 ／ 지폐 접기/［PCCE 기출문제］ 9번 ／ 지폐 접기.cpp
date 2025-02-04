#include <string>
#include <vector>

using namespace std;

//지폐를 지갑에 넣을 수 있는지 확인하는 함수
bool IsPossiblePutInWallet(const vector<int> &wallet, const vector<int> &bill){
    bool bIsPossible = false;
    if( wallet[0] >= bill[0] && wallet[1]>=bill[1]){
        bIsPossible = true;
    }
    
    if(wallet[0] >= bill[1] && wallet[1]>=bill[0]){
        bIsPossible = true;
    }
    return bIsPossible;
}

//지폐를 지갑에 넣을 수 있을 때까지 반으로 접는 함수
int GetAnswer(const vector<int> &wallet, vector<int> &bill){
    int answer = 0;
    while(false == IsPossiblePutInWallet(wallet,bill)){
        if(bill[0]>bill[1]){
            bill[0]=(bill[0]/2);
        }
        else{
            bill[1]=(bill[1]/2);
        }
        answer++;
    }
    return answer;
}

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    answer = GetAnswer(wallet, bill);
    return answer;
}