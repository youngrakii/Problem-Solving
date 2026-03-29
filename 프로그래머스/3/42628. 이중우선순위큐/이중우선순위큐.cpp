#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> operations) 
{
    vector<int> temp, answer;

    for (auto str : operations)
    {
        stringstream ss(str);
        char op;
        string num;
        
        ss>>op>>num;

        if (op == 'I')
            temp.push_back(stoi(num));

        else
        {
            if (num == "1" && !temp.empty())
                temp.erase(max_element(temp.begin(), temp.end()));

            else if(num == "-1" && !temp.empty())
                temp.erase(min_element(temp.begin(), temp.end()));
        }
    }
       priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int, vector<int>, less<int>> pq2;

    for (auto val : temp)
    {
        pq1.push(val);
        pq2.push(val);
    }

    if (pq1.empty() && pq2.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    else
    {
        answer.push_back(pq2.top());
        answer.push_back(pq1.top());
    }

    return answer;
}