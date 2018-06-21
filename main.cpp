//
// Created by Michael Rokitko on 19/06/2018.
//

#include "menu.h"
#include "Observer.h"
using namespace std;
int main()
{
    MotherShip* MyShip= nullptr;
    int userChoise = -1;
    string nameObs = "";
    while (userChoise != 9) {
        userChoise = menu();
        switch (userChoise) {

            case 1:
            {
                if(!MyShip) {
                    MyShip = new MotherShip();
                } else {
                    cout << "Only one Ship can be created!" << endl;
                }
                break;
            }
            case 2: {
                if(MyShip) {
                    cout << "Enter Observer name to add: " << endl;
                    cin.clear();
                    fflush(stdin);
                    cin >> nameObs;
                    MyShip->AttachObserver(new Observer(MyShip,nameObs));

                } else {
                    cout << "Please create ship first" << endl;
                }
                break;
            }
            case 3: {
                if(MyShip) {
                    cout << "Enter Observer name to delete: " << endl;
                    cin.clear();
                    fflush(stdin);
                    cin >> nameObs;
                    MyShip->DetachObserver(nameObs);



                } else {
                        cout << "Please create ship first" << endl;
                    }
                break;
            }
            case 4:
            {
                if(MyShip) {
                    MyShip->SetOperationMode(Regular);
                } else {
                    cout << "Please create ship first" << endl;
                }
                break;
            }
            case 5:
            {
                if(MyShip) {
                    MyShip->SetOperationMode(MaxSpeed);
                }else {
                    cout << "Please create ship first" << endl;
                }
                break;
            }
            case 6:
            {
                if(MyShip) {
                    MyShip->SetOperationMode(DangerMode);
                }else {
                    cout << "Please create ship first" << endl;
                }
                break;
            }
            case 7:
            {
                if(MyShip) {
                    MyShip->SetOperationMode(PowerReserve);
                }else {
                    cout << "Please create ship first" << endl;
                }
                break;
            }
            case 8:
            {
                if(MyShip) {
                    MyShip->getData();
                }else {
                    cout << "Please create ship with observers first" << endl;
                }
                break;

            }

            default:
                break;
            }
    }

    if(MyShip)
        delete (MyShip);
    cout << "Your Ship Was Destroyed, Good Bye!" << endl;
    return 0;
}