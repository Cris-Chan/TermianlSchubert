//
//  CoreMechanics.cpp
//  TermianlSchubert
//
//  Created by Cristian villanueva on 11/6/18.
//  Copyright © 2018 Cristian villanueva. All rights reserved.
//

#include "CoreMechanics.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>
//#include "Story.h"
//#include "CoreMechanics.h"
//#include "User.h"
//#include "SpoofedTerminalObject.h"
using std::cout;
using std::flush;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

void CoreMechanics::populateDir(){
    // Every dir should be lower case
    directories[0] = "users";
    directories[1] = "documents";
    directories[2] = "topsecretfiles";
    directories[3] = "downloads";
    directories[4] = "movies";
    directories[5] = "home";
    directories[6] = "desktop";
}

void CoreMechanics::populateCommands(){
    commands[0] = "cd";
    commands[1] = "ls";
    commands[2] = "delete";
    commands[3] = "read";
    commands[4] = "help";
    commands[5] = "stoptherussians";
}

void CoreMechanics::passedCommand(string command) const{
    
}

void CoreMechanics::printTextAnimation(const string& message) const{
    // Range loops are "for each" constructs; here: for each character in the string
    for (const char c: message)
    {
        // flush is used to make sure the buffer is emptied to the terminal immediately
        cout << c << flush;
        
        // Ask the thread to sleep for at least n millis.
        sleep_for(milliseconds(100));
    }
}

string CoreMechanics::getChoice()const{
    string response;
    cout << "\n What will you do? : ";
    getline(cin, response);
    return response;
}

void CoreMechanics::clearScreen()const{
    // well there are better ways to do this but its hard to implement when your unsure what the user will be using to run the code. this solution will run in until i come up with a better solution
    for(int x = 0; x<500; x++){
        cout << "\n";
    }
}

void CoreMechanics::animationLoading(int numberOfLoops)const{
    for(int x = 0; x < numberOfLoops; x++){
        clearScreen();
        cout << "Loading.";
        sleep_for(milliseconds(1000));
        clearScreen();
        cout << "Loading..";
        sleep_for(milliseconds(1000));
        clearScreen();
        cout << "Loading...";
        sleep_for(milliseconds(1000));
    }
    clearScreen();
}


bool CoreMechanics::isSupportedDir(string dir)const{
    bool realDir = false;
    for(int x = 0; x < dirCount; x++){
        if(directories[x] == dir){
            realDir = true;
            break;
        }
    }
    return realDir;
}


void CoreMechanics::renderDirContents(string currentDir)const{
    
    if(isSupportedDir(currentDir) != true){
        cout << "\n" << "-bash: cd: " << currentDir << " No such file or directory\n";
        cout << dirPath;
        return;
    }
    
    if(currentDir == "users"){
        cout << "\nPhil Schubert\n";
        cout << dirPath;
    }
    
    if(currentDir == "home"){
        cout << "\ndesktop\n";
        cout << "documents\n";
        cout << "topsecretfiles\n";
        cout << "downloads\n";
        cout << "movies\n";
        cout << "pictures\n";
        cout << "creative cloud files\n";
        cout << dirPath;
    }
    
    if(currentDir == "desktop"){
        cout << "\nHollow Knight.app\n";
        cout << "FolderThatHasAllOfACUStudentGrades\n";
        cout << "topsecretfiles\n";
        cout << "memeFolder\n";
        cout << "HotSauceCollage.png\n";
        cout << "notes.txt\n";
        cout << "messagingANON.app\n";
        cout << "notes2.txt\n";
        cout << "notes4.txt\n";
        cout << dirPath;
    }
    
    if(currentDir == "downloads"){
        cout << "\nrussianAgenda.txt\n";
        cout << "FullBeeMovie.mov\n";
        cout << "cat.png\n";
        cout << dirPath;
    }
    
    if(currentDir == "topsecretfiles"){
        cout << "\nrussianTransmission.txt\n";
        cout << "reminder.txt\n";
        cout << dirPath;
    }
    
    if(currentDir == "documents"){
        cout << "\nkungFuPandaMoviewScript.txt\n";
        cout << "newCookiesRecipe.pdf\n";
        cout << dirPath;
    }
    
    
}

void CoreMechanics::beginTerminalLoop(string startingDir){
   // the current dir contents should already be displayed along with the path.
    string input;
    
    while(true){
        getline(cin, input);
        stringstream inputStream(input);
        inputStream >> input;
        if(input == "cd"){
            if(inputStream >> input){
//                cout << "DEBUG: ok we in sum " << input << "   " << isSupportedDir(input);
                if(isSupportedDir(input)){
//                    cout << "DEBUG: GEEGOLLY";
                    currentDirLocation = input;
                    updateDirPath();
                    cout << dirPath;
                }
            }
            else{ // if nothing after "cd" or invalid
                cout << "please enter a valid directory\n";
                cout << dirPath;
            }
        }
        else if (input == "ls") {
//            cout << "DEBUG: EMPTY REQUEST";
            renderDirContents(currentDirLocation);
        }
        else if(input == "help"){
            cout << "\nTerminal Commands:" << endl << "cd \'direectory name\' - navigates to specified directory\nls - lists the contents of current Dir\nread \'file name\' - read out specified file if supported\n";
            cout << dirPath;
        }
        else if(input == "read"){
            if(inputStream >> input){
                read(input);
                cout << dirPath;
            }
        }
        else{
            cout << dirPath;
        }
    }
    
    
}


void CoreMechanics::read(string filename)const{
    if(filename == "russianTransmission.txt"){
        string text = "\nMr.Shubert has no idea of our EVIL plan...\nwe should move forward with activation soon, just in time for wildcat week >:)\nas long as no one hacks into his computer and decypts our evil activation files (og which there are 3) and combines them to gain acces to our internal systems and shut down our evil plans forever then this missian is GOLDEN heh, man im so smart\n\nVlad's Diaries entry #21\n\n";
        printTextAnimation(text);
    }
    else{
        cout << "unreadable......\n";
    }
}
