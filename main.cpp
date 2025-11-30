#include <bits/stdc++.h>
#include "movebox.h"
using namespace std;
int main()
{
    Map map;
    map.input();
    map.position();
    while (1)
    {
        system("cls");
        map.print();
        map.move();
        if (map.win)
        {
            system("cls");
            map.print();
            cout << "You win!" << endl;
            break;
        }
        else if (map.stop)
        {
            break;
        }
    }
    system("pause");
    return 0;
}