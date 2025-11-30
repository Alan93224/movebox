#include <bits/stdc++.h>
using namespace std;
class Map
{
public:
    Map() {}
    ~Map() {}
    int r, c, player_x, player_y, cnt, stop = 0, ans_x[10], ans_y[10], boxnum = 0, ansnum = 0;
    bool win = 0, hide = 0, reset = 0;
    vector<string> b;
    vector<string> b2;
    void input();
    void print();
    void position();
    void move();
};