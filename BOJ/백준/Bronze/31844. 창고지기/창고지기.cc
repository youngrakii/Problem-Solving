#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<char> warehouse(10);

    for (int i = 0; i < 10; ++i) {
        cin >> warehouse[i];
    }
    int robot_pos, box_pos, target_pos;
    for (int i = 0; i < 10; ++i) {
        if (warehouse[i] == '@') robot_pos = i;
        else if (warehouse[i] == '#') box_pos = i;
        else if (warehouse[i] == '!') target_pos = i;
    }
    int robot_to_box = abs(robot_pos - box_pos);
    int box_to_target = abs(box_pos - target_pos);


    int total_moves;

    if ((robot_pos < box_pos && box_pos < target_pos) || (robot_pos > box_pos && box_pos > target_pos)) {
        total_moves = robot_to_box + box_to_target;
        cout << total_moves - 1 << "\n";
    }
    else {
        cout << -1;
    }

    return 0;
}
