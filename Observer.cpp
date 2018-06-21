//
// Created by Michael Rokitko on 19/06/2018.
//

#include "Observer.h"

Observer::Observer(MotherShip *newMothership,string& name) {
    _name = name;
    Ship = newMothership;
    currentShipState = newMothership->GetOperationmode();
}

void Observer::CheckShipState() {
    currentShipState = Ship->GetOperationmode();
    allStatesData.push_back(currentShipState);


}

void Observer::PrintObservations() {
    cout << "Observer name is: " + _name << endl;
    cout << "States of ship observed by this observer were: [ " ;
    for (auto &State : allStatesData)
        switch (State) {
            case Regular: {
                cout << "Regular Mode, ";
                break;
            }
            case MaxSpeed: {
                cout << "MaxSpeed Mode, ";
                break;
            }
            case PowerReserve: {
                cout << "Power Reserve Mode, ";
                break;
            }
            case DangerMode: {
                cout << "Danger Mode, ";
                break;

                default:
                    break;
            }
        }
    cout << "]" << endl;
}



