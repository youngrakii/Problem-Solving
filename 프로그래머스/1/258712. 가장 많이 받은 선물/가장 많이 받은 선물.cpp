#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int n = friends.size();
    
    unordered_map<string, int> idx;
    for (int i = 0; i < n; i++) {
        idx[friends[i]] = i;
    }
    
    vector<vector<int>> give(n, vector<int>(n, 0));
    vector<int> given(n, 0);
    vector<int> received(n, 0);
    
    for (string g : gifts) {
        stringstream ss(g);
        string from, to;
        ss >> from >> to;
        
        int a = idx[from];
        int b = idx[to];
        
        give[a][b]++;
        given[a]++;
        received[b]++;
    }
    
    vector<int> giftScore(n);
    for (int i = 0; i < n; i++) {
        giftScore[i] = given[i] - received[i];
    }
    
    vector<int> nextGift(n, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (give[i][j] > give[j][i]) nextGift[i]++;
            else if (give[i][j] < give[j][i]) nextGift[j]++;
            else {
                if (giftScore[i] > giftScore[j]) nextGift[i]++;
                else if (giftScore[i] < giftScore[j]) nextGift[j]++;
            }
        }
    }
    
    int answer = 0;
    for (int x : nextGift) {
        answer = max(answer, x);
    }
    
    return answer;
}