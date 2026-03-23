#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long max_val =0;
vector<long long> origin_nums;
vector<char> origin_ops;
char op_types[3] = {'+','-','*'};
bool visited[3]={false,};
vector<char> selected_priority;


long long calculate(long long a, long long b, char op){
    if(op=='+') return a+b;
    if(op=='-') return a-b;
    if(op=='*') return a*b;
}

void solve(){
    vector<long long> nums = origin_nums;
    vector<char> ops = origin_ops;
    
    for(char target_op:selected_priority){
        for(int i=0; i<ops.size();){
            if(ops[i]==target_op){
                long long res = calculate(nums[i],nums[i+1],ops[i]);
                nums.erase(nums.begin()+i, nums.begin()+i+2);
                nums.insert(nums.begin()+i,res);
                ops.erase(ops.begin()+i);
            }
            else{
                i++;
            }
        }
    }
    max_val = max(max_val,abs(nums[0]));
}
void dfs(int depth){
    if(depth==3){
        solve();
        return;
    }
    
    for(int i=0; i<3; i++){
        if(!visited[i]){
            visited[i]=true;
            selected_priority.push_back(op_types[i]);
            
            dfs(depth+1);
            
            selected_priority.pop_back();
            visited[i]=false;
        }
    }
}
long long solution(string expression) {
    string temp = "";
    for(char c:expression){
        if(isdigit(c)) temp+=c;
        else{
            origin_nums.push_back(stoll(temp));
            origin_ops.push_back(c);
            temp="";
        }
    }
    origin_nums.push_back(stoll(temp));
    
    dfs(0);
    return max_val;
}