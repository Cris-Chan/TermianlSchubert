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
public:
    User() : gameEntity("noName"){
        isSudoUser = false;
        hasChangedGrades = false;
        hasReadRussianTutorial = false;
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
    
    //SETTERS
//    void inventorySET(){ return inventory;}
//    void userNameSET(string value){userName = value;}
    void isSudoUserSET(bool value){isSudoUser = value;}
    void hasChangedGradesSET(bool value){hasChangedGrades = value;}
    void hasReadRussianTutorialSET(bool value){hasReadRussianTutorial = value;}
    
    
    void addUnlockedCommand(string command){
        unlockedCommands.push_back(command);
    }
    bool hasCommand(string command){
        bool answer = false;
        
        for(auto it = unlockedCommands.begin(); it != unlockedCommands.end(); it++){
            if(*it == command)
                answer = true;
        }
        
        return answer;
    }
    
    bool isInInventory(string value){
        bool answer = false;
        
        for(auto itr = inventory.begin(); itr < inventory.begin(); itr++){
            if(value == *itr)
                answer = true;
        }
        
        return answer;
    }
    
    void renderInventory(){
        cout << endl << "INVENTORY(" << inventory.size() << ")" << endl << "---------------------";
        for(auto itr = inventory.begin(); itr != inventory.end(); itr++){
            cout << "\n[" << *itr << "]";
        }
        cout << endl << endl;
    }
    
    void addToInventory(string file){
        inventory.push_back(file);
    }
    
    
};
