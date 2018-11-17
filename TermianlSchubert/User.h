#include <iostream>
#include "gameEntity.h"
using namespace std;

class User : public gameEntity{
private:
    string inventory[5];
    int characterChoice; // this will not be used yet for the draft or ever lmao
public:
    User() : gameEntity("noName"){
        inventory[0] = "[]";
        inventory[1] = "[]";
        inventory[2] = "[]";
        inventory[3] = "[]";
        inventory[4] = "[]";
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
