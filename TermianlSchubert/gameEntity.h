#include <iostream>
using namespace std;

class gameEntity{
private:
    string name;
    string status;
    
    
public:
    gameEntity(string text){
        name = text;
        status = "existing";
    }
    
    string nameGET(){return name;}
    string statusGET(){return status;}
    
    void nameSET(string input){name = input;}
    void statusGET(string input){status = input;}
    
};

