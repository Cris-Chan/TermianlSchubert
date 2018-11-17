#include <iostream>
#include <vector>
//#include "Story.h"
//#include "CoreMechanics.h"
//#include "User.h"
//#include "SpoofedTerminalObject.h"
using namespace std;

class CoreMechanics{
private:
    string directories[8];
//    string nakedPath;
    string dirPath;
    string commands[6];
    string currentDirLocation;
    int dirCount;
public:
    CoreMechanics(){
//        nakedPath = "~";
        dirPath = "Schubert:~ philSchubertMacBook$ ";
        populateDir();
        populateCommands();
        dirCount = 7;
        currentDirLocation = "home";
    }
    
    void populateDir();
    void populateCommands();
    void passedCommand(string command) const;
    
    //GETTER
    string dirPathGET()const{return dirPath;}
    string currentDirLocationGET()const{return currentDirLocation;}
    
    //SETTER
    void dirPathSET(string value){dirPath = value;}
    void currentDirLocationSET(string value){currentDirLocation = value;}
    
    
    void updateDirPath(){
        dirPath = "Schubert:" + currentDirLocation + " philSchubertMacBook$ ";
    }
    
    void clearScreen()const;
    void printTextAnimation(const string& message)const;
    
    
    void prompEnterToContinue()const{string nothing; getline(cin, nothing);}
    string getChoice()const;
    
    
    void animationLoading(int numberOfLoops)const;
    
    
    //CONSOLE FUNCTIONS (most likely will be grouped into seperate function)----
    // will stay in core to be consistent with adventure game outline for now---
    
    void renderDirContents(string currentDir);
    void myTerminal()const;
    void beginTerminalLoop(string startingDir);
    void cd(string dir); // unfinished
    void ls()const; // unfinished
    void help()const; // unfinished
    void read(string filename)const; // unfinished
    void run(string exeName);
    bool isSupportedDir(string dir)const;
    
};


