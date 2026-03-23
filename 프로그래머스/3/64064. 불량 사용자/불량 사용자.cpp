#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<vector<string>> result_set;
vector<string> picked;
bool visited[8];

bool is_match(string u, string b){
    if(u.size()!=b.size()) return false;
    for(int i=0; i<u.size(); i++){
        if(b[i]=='*') continue;
        if(u[i]!=b[i]) return false;
    }
    return true;
}

void dfs(int idx, vector<string>& picked, const vector<string>& user_id, const vector<string>& banned_id){
    if(idx==banned_id.size()){
        vector<string> temp = picked;
        sort(temp.begin(), temp.end());
        result_set.insert(temp);
        return;
    }
    
    for(int i=0; i<user_id.size(); i++){
        if(!visited[i] && is_match(user_id[i], banned_id[idx])){
            visited[i]=true;
            picked.push_back(user_id[i]);
            dfs(idx+1, picked, user_id, banned_id);
            visited[i]=false;
            picked.pop_back();
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    //vector<string> picked;
    dfs(0,picked,user_id,banned_id);
    return result_set.size();
}