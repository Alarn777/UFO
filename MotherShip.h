//
// Created by Michael Rokitko on 19/06/2018.
//

#ifndef INC_4_MOTHERSHIP_H
#define INC_4_MOTHERSHIP_H

#include "Observer.h"

using namespace std;
class Observer;
typedef enum OperationMode {
    Regular,MaxSpeed,PowerReserve,DangerMode
} Modes;


class ShipPart {
public:
    ShipPart():currentWorkload(0) {}
    int& ReadWorkload() { return currentWorkload;}
    void SetWorkload(int newWorkLoad) {currentWorkload = newWorkLoad;}
    virtual void print() = 0;

    virtual ~ShipPart() = default;
protected:
    int currentWorkload;
};


class Engine : public ShipPart{
public:
    Engine() {currentWorkload = 0;}
    void print() { cout << "---------------------------------------" << endl;  cout << "Engines now at " << currentWorkload << "% power" << endl;}
    ~Engine() = default;
private:

};
class LivingUnit : public ShipPart{
public:
    LivingUnit() {currentWorkload = 0;}
    void print() { cout << "Living Units now at " << currentWorkload << "% power" << endl;}

    ~LivingUnit() = default;
};
class Shield : public ShipPart{
public:
    Shield() {currentWorkload = 0;}
    void print() { cout << "Shields now at " << currentWorkload << "% power" << endl; cout << "---------------------------------------" << endl;}

    ~Shield() = default;
};
class ArtGravity : public ShipPart{
public:
    ArtGravity() {currentWorkload = 0;}
    void print() { cout << "Artificial Gravity now at " << currentWorkload << "% power" << endl; }

    ~ArtGravity() = default;
};

class MotherShip {
public:
    MotherShip();
    void SetOperationMode(int newMode) {applyModelBehaviour(newMode);}
    int& GetOperationmode() { return currentOperationMode; }
    void Notify();
    void AttachObserver(Observer* newObserver);
    void DetachObserver(string& nameObserv);
    ~MotherShip();
    void getData();

private:
    void applyModelBehaviour(int& operationMode);
    int currentOperationMode;
    vector<ShipPart*> shipParts;
    vector<Observer*> Observers;
};


#endif //INC_4_MOTHERSHIP_H
