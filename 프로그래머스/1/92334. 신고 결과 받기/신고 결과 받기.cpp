#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    
    //map의 첫번째 원소에는 신고 당한사람, 두번째 set 컨테이너에는 해당 사람을 신고한 사람(set이라 중복없음)
    map<string,set<string>> rp;
    for(const auto& r : report)
    {
        stringstream s(r);
        string a;
        string b;
        s >> a;
        s >> b;
        rp[b].insert(a);
    }
    //신고 한 횟수 체크해서 메일받을 사람과 횟수 담기
    map<string,int> result;
    for(const auto& r : rp)
    {
        if(r.second.size() >= k)
        {
            for(const auto& s : r.second)
            {
                result[s]++;
            }
        }
    }
    //메일 보낼 횟수 넣기
    for(int i = 0; i < id_list.size(); i++)
    {
        answer[i] = result[id_list[i]];
    }
    
    return answer;
}