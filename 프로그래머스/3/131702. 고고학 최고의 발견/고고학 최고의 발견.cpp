#include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int dy[5] { 0, 0, 0, 1, -1 };
int dx[5] { 0, -1, 1, 0, 0 };
int result = INT_MAX;

// 선택한 (y, x)의 위치를 isClockwise 방향으로 회전
void rotate(vector<vector<int>>& clockHands, int y, int x, int count, bool isClockwise = true)
{
    // 선택된 위치를 기준으로 5번의 반복(현재 위치, 좌, 우, 상, 하)
    for(int i = 0; i < 5; ++i)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];
        
        // 영역 자체를 벗어났다면, 수행하지 않음
        if(yy == -1 || xx == -1 || yy == clockHands.size() || xx == clockHands.size())
            continue;
        
        // isClockwise(시계 방향)이라면, +count(시계방향) 아니라면 -count(시계반대방향)
        clockHands[yy][xx] = clockHands[yy][xx] + (isClockwise ? +count : -count);
        
        // -값이 되면 적절하게 수정
        if(clockHands[yy][xx] < 0)
            clockHands[yy][xx] += 4;

        // 3보다 커질 수 없기에 적절히 수정
        clockHands[yy][xx] %= 4;
    }
}

// 현재 형상이 모두 12시로 맞춰져 있는가?
bool check(vector<vector<int>>& clockHands)
{
    for(int i = 0; i < clockHands.size(); ++i)
        for(int j = 0; j < clockHands.size(); ++j)
            if(clockHands[i][j])
                return false;
    
    return true;
}

int DFS(vector<vector<int>>& clockHands, int row, int col, int cnt)
{
    // 모든 시계를 확인하고 최소 이동 횟수 업데이트
    if (check(clockHands))
        return cnt;
    
    // 마지막에 도달하였을 때, check가 안되었다면, 이 방법으로는 시계를 정렬할 수 없음
    if (row == clockHands.size())
        return INT_MAX;  
    
    // 만약 누적된 cnt가 result 이상이라면, 더 이상 검사할 필요가 없기에 리턴
    if (cnt >= result)
        return INT_MAX;
    
    // 해당 위치를 0~3번 돌려 경우의수를 확장
    for (int i = 0; i < 4; ++i) 
    {
        // i만큼 시계 방향으로 회전
        rotate(clockHands, row, col, i, true);
        
        // 현재 row가 1 이상이면서, 현재 위치 바로 위 값이 0이 아니라면? -> 누적된 이 방법으로는 시계를 맞출 수 없음
        if (row && clockHands[row - 1][col]) 
        {
            // 회전 전으로 복구(반시계 방향 회전)
            rotate(clockHands, row, col, i, false);
            continue;
        }
        
        // 다음 위치 계산
        int nextRow = (col + 1 == clockHands.size()) ? row + 1 : row; // col이 끝에 도달하였다면, row를 증가, 아니라면 유지
        int nextCol = (col + 1) % clockHands.size(); // 다음 col은 1씩 증가
        
        // cnt는 i만큼 더하기 (i만큼 회전한 것이기 때문)
        result = min(result, DFS(clockHands, nextRow, nextCol, cnt + i));
        
        // 재귀가 끝나면 원래 상태로 되돌리기
        rotate(clockHands, row, col, i, false);
    }
    
    return result;
}

int solution(vector<vector<int>> clockHands) {
    return DFS(clockHands, 0, 0, 0);
}