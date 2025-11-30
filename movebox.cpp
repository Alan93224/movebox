#include <bits/stdc++.h>
#include "movebox.h"
#include <fstream>
#include <conio.h>
using namespace std;
void Map::input()
{
    string s;
    cout << "Input your file name." << endl;
    cin >> s;
    ifstream ifs(s, ios::in);
    ofstream out;
    out.open("box.txt");
    ifs >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        string str;
        ifs >> str;
        b.push_back(str);
    }
    b2 = b;
    ifs.close();
}
void Map::print()
{
    for (int j = 0; j < r; j++)
    {
        for (int i = 0; i < b[j].size(); i++)
        {

            cout << b[j][i];
        }
        cout << endl;
    }
}
void Map::position()
{
    cnt = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            if (b[i][j] == '0')
            {
                player_x = j;
                player_y = i;
            }
            if (b[i][j] == '2')
            {
                ans_x[ansnum] = j;
                ans_y[ansnum] = i;
                ansnum++;
                cnt++;
            }
        }
    }
}
void Map::move()
{
    int input = getch();
    switch (input)
    {
    case 72:
    {
        if (b[player_y - 1][player_x] == '-')
        {
            b[player_y - 1][player_x] = '0';
            if (hide == 1)
                b[player_y][player_x] = '2';
            else
                b[player_y][player_x] = '-';
            position();
            hide = 0;
        }
        else if (b[player_y - 1][player_x] == '1')
        {
            if (b[player_y - 2][player_x] == '2')
            {
                b[player_y - 2][player_x] = '1';
                b[player_y - 1][player_x] = '0';
                if (hide == 1)
                    b[player_y][player_x] = '2';
                else
                    b[player_y][player_x] = '-';
                position();
                if (cnt == 0)
                    win = 1;
                hide = 0;
            }
            else if (b[player_y - 2][player_x] == '-')
            {
                b[player_y - 2][player_x] = '1';
                b[player_y - 1][player_x] = '0';
                if (hide == 1)
                    b[player_y][player_x] = '2';
                else
                    b[player_y][player_x] = '-';
                player_y--;
                int h = 0;
                for (int i = 0; i < ansnum; i++)
                {
                    if (ans_x[i] == player_x && ans_y[i] == player_y)
                        h = 1;
                }
                if (h == 1)
                    hide = 1;
                else
                    hide = 0;
            }
        }
        else if (b[player_y - 1][player_x] == '2')
        {
            b[player_y - 1][player_x] = '0';
            b[player_y][player_x] = '-';
            position();
            hide = 1;
        }
        break;
    }
    case 80:
    {
        if (b[player_y + 1][player_x] == '-')
        {
            b[player_y + 1][player_x] = '0';
            if (hide)
                b[player_y][player_x] = '2';
            else
                b[player_y][player_x] = '-';
            position();
            hide = 0;
        }
        else if (b[player_y + 1][player_x] == '1')
        {
            if (b[player_y + 2][player_x] == '2')
            {
                b[player_y + 2][player_x] = '1';
                b[player_y + 1][player_x] = '0';
                if (hide == 1)
                    b[player_y][player_x] = '2';
                else
                    b[player_y][player_x] = '-';
                position();
                if (cnt == 0)
                    win = 1;
                hide = 0;
            }
            else if (b[player_y + 2][player_x] == '-')
            {
                b[player_y + 2][player_x] = '1';
                b[player_y + 1][player_x] = '0';
                if (hide == 1)
                    b[player_y][player_x] = '2';
                else
                    b[player_y][player_x] = '-';
                position();
                int h = 0;
                for (int i = 0; i < ansnum; i++)
                {
                    if (ans_x[i] == player_x && ans_y[i] == player_y)
                        h = 1;
                }
                if (h == 1)
                    hide = 1;
                else
                    hide = 0;
            }
        }
        else if (b[player_y + 1][player_x] == '2')
        {
            b[player_y + 1][player_x] = '0';
            b[player_y][player_x] = '-';
            position();
            hide = 1;
        }
        break;
    }
    case 75:
    {
        if (b[player_y][player_x - 1] == '-')
        {
            b[player_y][player_x - 1] = '0';
            if (hide == 1)
                b[player_y][player_x] = '2';
            else
                b[player_y][player_x] = '-';
            position();
            hide = 0;
        }
        else if (b[player_y][player_x - 1] == '1')
        {
            if (b[player_y][player_x - 2] == '2')
            {
                b[player_y][player_x - 2] = '1';
                b[player_y][player_x - 1] = '0';
                if (hide == 1)
                    b[player_y][player_x] = '2';
                else
                    b[player_y][player_x] = '-';
                position();
                if (cnt == 0)
                    win = 1;
                hide = 0;
            }
            else if (b[player_y][player_x - 2] == '-')
            {
                b[player_y][player_x - 2] = '1';
                b[player_y][player_x - 1] = '0';
                if (hide == 1)
                    b[player_y][player_x] = '2';
                else
                    b[player_y][player_x] = '-';
                position();
                int h = 0;
                for (int i = 0; i < ansnum; i++)
                {
                    if (ans_x[i] == player_x && ans_y[i] == player_y)
                        h = 1;
                }
                if (h == 1)
                    hide = 1;
                else
                    hide = 0;
            }
        }
        else if (b[player_y][player_x - 1] == '2')
        {
            b[player_y][player_x - 1] = '0';
            b[player_y][player_x] = '-';
            position();
            hide = 1;
        }
        break;
    }
    case 77:
    {
        if (b[player_y][player_x + 1] == '-')
        {
            b[player_y][player_x + 1] = '0';
            if (hide == 1)
                b[player_y][player_x] = '2';
            else
                b[player_y][player_x] = '-';
            position();
            hide = 0;
        }
        else if (b[player_y][player_x + 1] == '1')
        {
            if (b[player_y][player_x + 2] == '2')
            {
                b[player_y][player_x + 2] = '1';
                b[player_y][player_x + 1] = '0';
                if (hide == 1)
                    b[player_y][player_x] = '2';
                else
                    b[player_y][player_x] = '-';
                position();
                if (cnt == 0)
                    win = 1;
                hide = 0;
            }
            else if (b[player_y][player_x + 2] == '-')
            {
                b[player_y][player_x + 2] = '1';
                b[player_y][player_x + 1] = '0';
                if (hide == 1)
                    b[player_y][player_x] = '2';
                else
                    b[player_y][player_x] = '-';
                position();
                int h = 0;
                for (int i = 0; i < ansnum; i++)
                {
                    if (ans_x[i] == player_x && ans_y[i] == player_y)
                        h = 1;
                }
                if (h == 1)
                    hide = 1;
                else
                    hide = 0;
            }
        }
        else if (b[player_y][player_x + 1] == '2')
        {
            b[player_y][player_x + 1] = '0';
            b[player_y][player_x] = '-';
            position();
            hide = 1;
        }
        break;
    }
    case 'r':
    {
        b = b2;
        position();
        break;
    }
    case '0':
    {
        stop = 1;
        break;
    }
    }
}