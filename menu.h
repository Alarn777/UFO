//
// Created by Michael Rokitko on 10/06/2018.
//

#ifndef PLANES_MENU_H
#define PLANES_MENU_H
#include <iostream>
#include <string>

using namespace std;

int menu() {
    int decision = -1;
    int const menueEnd = 9;
    while (decision != menueEnd) {
        cout << "----------------ヽ(ˇヘˇ)ノ-------------------" << endl;
        cout << "To Create new Mothership press             1" << endl;
        cout << "To Attach Observer to the Mothership       2" << endl;
        cout << "To Detach Observer from the Mothership     3" << endl;
        cout << "Fly regularly                              4" << endl;
        cout << "Enter Full Speed mode                      5" << endl;
        cout << "Defend yourself from enemy ship            6" << endl;
        cout << "Save power to survive                      7" << endl;
        cout << "To Print all states passed                 8" << endl;
        cout << "To Exit press                              9" << endl;
        cout << "--------------------------------------------" << endl;
        do                                                  //protection from wrong intput
        {
            cin >> decision;
            if (decision < 1 || decision > menueEnd) {
                cout << "Not a valid choice, please enter menu number!\n";
                decision = 32;
                cin.clear();
                fflush(stdin);
                char temp[100];
                cin.getline(temp, 100);
                continue;
            }

        } while (decision < 1 || decision > menueEnd);
        return decision;
    }
}
#endif //PLANES_MENU_H
