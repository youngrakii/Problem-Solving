#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

bool genlistSort(pair<string,int> a, pair<string,int> b){
    return a.second>b.second;
}

bool playslistSort(pair<int,int> a, pair<int,int> b){
    return a.first>b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays){
    vector<int> answer;
    map<string,int> genlist;
    vector<pair<string,int>> genlistv;
    
    for(int i=0; i<genres.size(); i++){
        genlist[genres[i]]+=plays[i];
    }
    
    genlistv.assign(genlist.begin(),genlist.end());
    sort(genlistv.begin(),genlistv.end(),genlistSort);
    
    for(int i=0; i<genlistv.size(); i++){
        vector<pair<int,int>> playslist;
        string currGenres=genlistv[i].first;
        
        for(int j=0; j<genres.size(); j++){
            if(genres[j]==currGenres){
                playslist.push_back({plays[j],j});
            }
        }
        
        sort(playslist.begin(), playslist.end(), playslistSort);
        
        for(int j=0; j<playslist.size() && j<2; j++){
            answer.push_back(playslist[j].second);
        }
    }
    
    return answer;
}