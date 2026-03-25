#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    for(int i=0; i<new_id.size(); i++){
        new_id[i] = tolower(new_id[i]);
    }
    
    string filtered="";
    for(char c:new_id){
        if(islower(c)||isdigit(c)||c=='-'||c=='_'||c=='.') filtered+=c;
    }
    new_id = filtered;
    
    string condensed="";
    for(int i=0; i<new_id.size(); i++){
        if(new_id[i]=='.'&& new_id[i-1]=='.') continue;
        condensed+=new_id[i];
    }
    new_id = condensed;
    
    if(!new_id.empty() && new_id.front()=='.') new_id.erase(0,1);
    if(!new_id.empty() && new_id.back()=='.') new_id.pop_back();
    
    if(new_id.empty()) new_id = "a";
    
    if(new_id.size()>=16) {
        new_id=new_id.substr(0,15);
        if(new_id.back()=='.') new_id.pop_back();
    }
    
    if(new_id.size()<3){
        while(true){
            new_id+=new_id.back();
            if(new_id.size()==3) break;
        }
    }
    
    return new_id;
}