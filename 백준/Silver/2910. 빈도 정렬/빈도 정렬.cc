#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
 
int main() {
    int N, C;
    std::cin >> N >> C;
 
    std::map<int, int> frequencyMap;
    std::map<int, int> orderMap;
    int number;
 
    for (int i = 0; i < N; i++) {
        std::cin >> number;
        frequencyMap[number]++;
 
        if (orderMap[number] == 0)
            orderMap[number] = i + 1;
    }
 
    std::vector<std::pair<int, int>> frequencyList(frequencyMap.begin(), frequencyMap.end());
 
    std::sort(frequencyList.begin(), frequencyList.end(), [&](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if (a.second == b.second)
        return orderMap[a.first] < orderMap[b.first]; // 기존의 순서 지키기
 
    return a.second > b.second;
        });
 
    for (const auto& freq : frequencyList) {
        for (int i = 0; i < freq.second; i++) {
            std::cout << freq.first << " ";
        }
    }
 
    return 0;
}
