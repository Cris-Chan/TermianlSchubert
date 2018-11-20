#include <iostream>
#include <vector>
#include "gameEntity.h"
using namespace std;

class User : public gameEntity{
private:
//    string inventory[5];
    vector<string> inventory;
    vector<string> unlockedCommands;
    bool isSudoUser; // this will not be used yet for the draft or ever lmao
    bool hasChangedGrades;
    bool hasReadRussianTutorial;
    int foundFilesCount;
public:
    User() : gameEntity("noName"){
        isSudoUser = false;
        hasChangedGrades = false;
        hasReadRussianTutorial = false;
        foundFilesCount = 0;
    }
    User(string passedName) : gameEntity(passedName){
        User();
        nameSET(passedName);
    }
    
    
    //GETTERS
//    string userNameGET(){return userName;}
    bool isSudoUserGET(){return isSudoUser;}
    bool hasChangedGradesGET(){return hasChangedGrades;}
    bool hasReadRussianTutorialGET(){return hasReadRussianTutorial;}
    int foundFilesCountGET(){return foundFilesCount;}
    
    //SETTERS
//    void inventorySET(){ return inventory;}
//    void userNameSET(string value){userName = value;}
    void isSudoUserSET(bool value){isSudoUser = value;}
    void hasChangedGradesSET(bool value){hasChangedGrades = value;}
    void hasReadRussianTutorialSET(bool value){hasReadRussianTutorial = value;}
    void foundFilesCountSET(int value){foundFilesCount = value;}
    
    
    void addUnlockedCommand(string command){unlockedCommands.push_back(command);}
    
    bool hasCommand(string command)const;
    
    bool isInInventory(string value)const;
    
    void renderInventory()const;
    
    void addToInventory(string file){
        inventory.push_back(file);
    }
    
    
};
