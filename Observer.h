//
// Created by Michael Rokitko on 19/06/2018.
//

#ifndef INC_4_OBSERVER_H
#define INC_4_OBSERVER_H

#include <iostream>
#include <string>
#include <vector>
#include "MotherShip.h"

using namespace std;
class MotherShip;
class Observer {
public:
    Observer(MotherShip* newMothership,string& name);
    void CheckShipState();
    void PrintObservations();
    string& getName() { return _name;}
private:
    int currentShipState;
    MotherShip* Ship;
    vector<int> allStatesData;
    string _name;
};

















#endif //INC_4_OBSERVER_H
