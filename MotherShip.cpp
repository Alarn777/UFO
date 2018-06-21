//
// Created by Michael Rokitko on 19/06/2018.
//
#include <time.h>
#include "MotherShip.h"
struct tm * timeinfo;
MotherShip::MotherShip() {
    shipParts.push_back(new Engine());
    shipParts.push_back(new ArtGravity());
    shipParts.push_back(new LivingUnit());
    shipParts.push_back(new Shield());
    currentOperationMode = -1;
    SetOperationMode(Regular);

    time_t rawtime;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    cout << "Ship was assembled on planet Earth at "; printf (asctime (timeinfo)); cout << "and now started it's flight in space" << endl;
    Notify();
}



void MotherShip::applyModelBehaviour(int &operationMode) {
    //MaxSpeed,PowerReserve,DangerMode
    if (operationMode == this->GetOperationmode())
    {
//        Notify();
        cout << "Keeping her steady Captain!" << endl;
        return;
    }

    else {
        if (operationMode == Regular) {
            shipParts[0]->SetWorkload(50);
            shipParts[1]->SetWorkload(100);
            shipParts[2]->SetWorkload(50);
            shipParts[3]->SetWorkload(0);
        }
        if (operationMode == MaxSpeed) {
            shipParts[0]->SetWorkload(100); //max
            shipParts[1]->SetWorkload(0);   //offline
            shipParts[2]->SetWorkload(50);  //regular
            shipParts[3]->SetWorkload(25);  //partial
        }
        if (operationMode == PowerReserve) {
            shipParts[0]->SetWorkload(0);
            shipParts[1]->SetWorkload(0);
            shipParts[2]->SetWorkload(25);
            shipParts[3]->SetWorkload(0);
        }
        if (operationMode == DangerMode) {
            shipParts[0]->SetWorkload(50);
            shipParts[1]->SetWorkload(0);
            shipParts[2]->SetWorkload(10);
            shipParts[3]->SetWorkload(100);
        }
        currentOperationMode = operationMode;
        Notify();
        for (auto &shipPart : shipParts)
            shipPart->print();
    }

}

void MotherShip::Notify() {
    for (auto &Observer : Observers)
        Observer->CheckShipState();
}

void MotherShip::AttachObserver(Observer* newObserver) {
    Observers.push_back(newObserver);
    cout << "Observer attached" << endl;
}

void MotherShip::DetachObserver(string& nameObserv) {
    bool deleted = false;
    for (int i = 0;i < Observers.size();i++) {
        if (nameObserv == Observers[i]->getName()) {
            Observers.erase(Observers.begin() + i);
            deleted = true;
        }
    }
    if(deleted)
        cout << "Deleted Observer" + nameObserv << endl;
    else
        cout << "No Observer with name " + nameObserv << " found" << endl;

}




MotherShip::~MotherShip() {

    for (auto &shipPart : shipParts) {
        shipParts.erase(shipParts.begin());
    }
    for (auto &Observer : Observers){
        Observers.erase(Observers.begin());

    }

}

void MotherShip::getData() {
    for (auto &Observer : Observers) {
        Observer->PrintObservations();
    }
}
