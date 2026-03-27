#include <string>
#include <vector>

using namespace std;

string toBinary(int n){
    string result = "";
    while(n>0){
        result = char((n%2)+'0') + result;
        n/=2;
    }
    return result;
}
vector<int> solution(string s) {
    int transformCount =0;
    int removedZeroCount =0;
    
    while(s!="1"){
        int oneCount=0;
        
        for(char c:s){
            if(c=='0') removedZeroCount++;
            else oneCount++;
        }
        
        s=toBinary(oneCount);
        transformCount++;
    }
    
    return {transformCount, removedZeroCount};
}