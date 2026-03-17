

#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    set<string> s;

    string blinds = message;
    for (vector<int> range: spoiler_ranges) {
        for (int i=range[0]; i<=range[1]; ++i) {
            if (blinds[i] != ' ')
                blinds[i] = '*';
        }
    }

    stringstream ss(blinds);
    string word;
    while (ss >> word) {
        s.insert(word);
    }

    ss.clear();
    ss.str(message);
    while(ss >> word) {
        if (s.count(word) == 0) {
            ++answer;
            s.insert(word);
        }
    }

    return answer;
}