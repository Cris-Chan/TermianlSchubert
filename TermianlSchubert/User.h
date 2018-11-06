#include <iostream>
#include "gameEntity.h"
using namespace std;

class User : public gameEntity{
private:
    string inventory[2];
    int characterChoice; // this will not be used yet for the draft
public:
    User() : gameEntity("noName"){
        inventory[0] = "[]";
        inventory[1] = "[]";
        characterChoice = 0;
    }
    User(string passedName) : gameEntity(passedName){
        User();
        nameSET(passedName);
    }
    
    //GETTERS
    string* inventoryGET(){ return inventory;}
//    string userNameGET(){return userName;}
    int characterChoiceGET(){return characterChoice;}
    
    //SETTERS
//    void inventorySET(){ return inventory;}
//    void userNameSET(string value){userName = value;}
    void characterChoiceSET(int value){characterChoice = value;}
};
