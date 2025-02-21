#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) 
{
    vector<int> temp, answer;

    for (const auto& str : operations)
    {
        string tmp = str.substr(2);

        if (str[0] == 'I')
            temp.push_back(stoi(tmp));

        else
        {
            if (tmp == "1" && !temp.empty())
                temp.erase(max_element(temp.begin(), temp.end()));

            else if(tmp == "-1" && !temp.empty())
                temp.erase(min_element(temp.begin(), temp.end()));
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int, vector<int>, less<int>> pq2;

    for (const auto& val : temp)
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