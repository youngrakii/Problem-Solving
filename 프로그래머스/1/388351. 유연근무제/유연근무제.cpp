//#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
//#include <map>
//#include <unordered_map>
//#include <set>
//#include <unordered_set>
//#include <numeric>

using namespace std;

bool determineAllowingTime(int preferredTime, int actualTime) {
    // converting preferred time into hour and minute
    int preferredMinute = preferredTime % 100; // %는 나머지 계산 /는 몫 계산
    int preferredHour = (preferredTime - preferredMinute) / 100;
    
    // converting actual time into hour and minute
    int actualMinute = actualTime % 100;
    int actualHour = (actualTime - actualMinute) / 100;
    
    // getting the allowed range of preferred time
    int allowedMinute = preferredMinute + 10;
    int allowedHour = preferredHour;
    if (allowedMinute > 59) {
        allowedHour += 1;
        allowedMinute -= 60;
    }

    bool isOnTime = true;
    if (allowedHour < actualHour) { isOnTime = false; }
    else if (allowedHour == actualHour) {
        if (allowedMinute < actualMinute) { isOnTime = false; }
    }
    
    return isOnTime;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for (int i = 0; i < timelogs.size(); ++i) {
        int day = startday;
        bool isOnTime = true;
        
        for (int j = 0; j < 7; ++j) {
            if (day < 6) {
                if (determineAllowingTime(schedules[i], timelogs[i][j]) == false) {
                    isOnTime = false;
                    break;
                }
            }
            
            day++;
            if (day == 8) { day = 1; }
        }
        
        if (isOnTime == true) { answer++; }
    }
    
    return answer;
}