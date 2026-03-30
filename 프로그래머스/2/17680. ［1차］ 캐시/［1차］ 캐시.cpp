#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0) return cities.size() * 5;

    int time = 0;
    vector<string> cache;

    for (string city : cities) {
        for (char& c : city) c = tolower(c);

        auto it = find(cache.begin(), cache.end(), city);

        if (it != cache.end()) {
            time += 1;
            cache.erase(it);
            cache.push_back(city);
        } else {
            time += 5;
            if (cache.size() == cacheSize) {
                cache.erase(cache.begin());
            }
            cache.push_back(city);
        }
    }

    return time;
}