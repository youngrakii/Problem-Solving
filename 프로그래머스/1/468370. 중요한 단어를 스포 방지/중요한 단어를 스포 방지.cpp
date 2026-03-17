#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct WordInfo {
    string word;
    int start;
    int end;
    bool isSpoiler;
    int revealStep; // 몇 번째 클릭 후 완전히 공개되는지
};

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int n = message.size();
    int m = spoiler_ranges.size();

    // 각 문자 위치가 몇 번째 spoiler 구간에 속하는지 기록
    // 0이면 spoiler 아님, 1~m이면 해당 클릭 번호
    vector<int> spoilerMark(n, 0);
    for (int i = 0; i < m; i++) {
        int s = spoiler_ranges[i][0];
        int e = spoiler_ranges[i][1];
        for (int j = s; j <= e; j++) {
            spoilerMark[j] = i + 1;
        }
    }

    // message를 단어 단위로 분리
    vector<WordInfo> words;
    int i = 0;
    while (i < n) {
        int start = i;
        while (i < n && message[i] != ' ') i++;
        int end = i - 1;

        string w = message.substr(start, end - start + 1);

        bool isSpoiler = false;
        int revealStep = 0;

        for (int p = start; p <= end; p++) {
            if (spoilerMark[p] > 0) {
                isSpoiler = true;
                revealStep = max(revealStep, spoilerMark[p]);
            }
        }

        words.push_back({w, start, end, isSpoiler, revealStep});
        i++; // 공백 하나 넘기기
    }

    // 일반 구간(스포일러 아님)에 등장한 단어 문자열 저장
    unordered_set<string> normalWords;
    for (const auto& info : words) {
        if (!info.isSpoiler) {
            normalWords.insert(info.word);
        }
    }

    // 각 클릭 시점에 공개되는 spoiler 단어들 저장
    vector<vector<int>> revealedAtStep(m + 1);
    for (int idx = 0; idx < words.size(); idx++) {
        if (words[idx].isSpoiler) {
            revealedAtStep[words[idx].revealStep].push_back(idx);
        }
    }

    // 클릭 순서대로 중요한 단어 판단
    int answer = 0;
    unordered_set<string> alreadyCounted;

    for (int step = 1; step <= m; step++) {
        for (int idx : revealedAtStep[step]) {
            const string& w = words[idx].word;

            // 1) 스포일러 단어
            // 2) 일반 구간에 등장한 적 없음
            // 3) 이전에 중요한 단어로 세지 않음
            if (normalWords.find(w) == normalWords.end() &&
                alreadyCounted.find(w) == alreadyCounted.end()) {
                answer++;
                alreadyCounted.insert(w);
            }
        }
    }

    return answer;
}