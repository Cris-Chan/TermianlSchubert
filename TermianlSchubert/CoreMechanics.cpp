//
//  CoreMechanics.cpp
//  TermianlSchubert
//
//  Created by Cristian villanueva on 11/6/18.
//  Copyright © 2018 Cristian villanueva. All rights reserved.
//

#include "CoreMechanics.h"
//#include "User.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>
#include <unistd.h>
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
    // this is every possible directory you can go to
    directories[0] = "acustudentgrades";
    directories[1] = "documents";
    directories[2] = "topsecretfiles";
    directories[3] = "downloads";
    directories[4] = "movies";
    directories[5] = "home";
    directories[6] = "desktop";
    directories[7] = "myhome"; //TODO: migrate this and delete it
    //TODO: simplify the direcoties, for easy nav
}

void CoreMechanics::populateCommands(){
    // !!!: i actually never ended up using this lol
    commands[0] = "cd";
    commands[1] = "ls";
    commands[2] = "delete";
    commands[3] = "read";
    commands[4] = "help";
    commands[5] = "stoptherussians";
}

void CoreMechanics::passedCommand(string command) const{ // ???: what is this?
    
}

void CoreMechanics::printTextAnimation(const string& message) const{
    // Range loops are "for each" constructs; here: for each character in the string
    for (const char c: message)
    {
        // flush is used to make sure the buffer is emptied to the terminal immediately
        cout << c << flush;
        
        // Ask the thread to sleep for at least n millis.
        sleep_for(milliseconds(0));
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
    clearScreen();
    std::cout << "Booting " << '-' << std::flush;
    for (int x = 0; x < numberOfLoops; x++) {
        sleep(0);
        std::cout << "\b\\" << std::flush;
        sleep(0);
        std::cout << "\b|" << std::flush;
        sleep(0);
        std::cout << "\b/" << std::flush;
        sleep(0);
        std::cout << "\b-" << std::flush;
    }
    clearScreen();
}
void CoreMechanics::animationLoading(int numberOfLoops, string passedText)const{
    clearScreen();
    std::cout << passedText << " -" << std::flush;
    for (int x = 0; x < numberOfLoops; x++) {
        sleep(0);
        std::cout << "\b\\" << std::flush;
        sleep(0);
        std::cout << "\b|" << std::flush;
        sleep(0);
        std::cout << "\b/" << std::flush;
        sleep(0);
        std::cout << "\b-" << std::flush;
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


void CoreMechanics::renderDirContents(string currentDir){
    
    
    if(isSupportedDir(currentDir) != true and currentDir != "myhome"){
        cout << "\n" << "-bash: cd: " << currentDir << " No such file or directory\n";
        cout << dirPath;
//        return;
    }
    
    if(currentDir == "acustudentgrades"){
        if(gamePlayer->hasChangedGradesGET()){
            cout << "\nMac Demarco grades\n";
            cout << "Bensons grades\n";
            cout << gamePlayer->nameGET() + "'s grades\n";
            cout << "Travis Towel's grades\n";
            cout << "Jerry's grades\n";
            cout << "cookie recipie\n";
            cout << "Prather's Grades\n";
            cout << dirPath;
        }
        else{
            gamePlayer->addUnlockedCommand("read");
            gamePlayer->hasChangedGradesSET(true);
            objectiveSET("Find those darn commy activation files!!");
            clearScreen();
            printTextAnimation("Oh boy, I found my grades!\nWhat should i set my bible class average to?: ");
            int dummyGrade;
            cin >> dummyGrade;
            clearScreen();
            printTextAnimation("Ohhhhhh yeaaaaaa that grade will get me through the class\nBut somthing feels off about Mr.Schuberts MacBook....\nim kind of getting a russian sleeper agent vibe from it for some reason\nI better check things out just to be sure.\n");
            prompEnterToContinue();
            prompEnterToContinue();
            clearScreen();
            printTextAnimation("you have unlocked the \"read\" unix command *cue flashy sound effect*\nnow you can read .txt files whenever you want\n");
            prompEnterToContinue();
            cout << dirPath;
        }
    }
    
    if(currentDir == "home"){
        cout << "\nrussianTransmission.txt\n";// cant read this until read command is unlocked
        cout << "desktop\n";
        cout << "documents\n";
        cout << "topsecretfiles\n"; // this should require sudo access
        cout << "downloads\n";
        
        cout << dirPath;
    }
    
    if(currentDir == "desktop"){
        cout << "\nHollow Knight.app\n";
        cout << "memeFolder\n";
        cout << "HotSauceCollage.psd\n";
        cout << "dailynotes.txt\n";
        cout << "spotify.app\n";
//        cout << "notes2.txt\n";
//        cout << "notes4.txt\n";
        cout << dirPath;
    }
    
    
    if(currentDir == "downloads"){
        cout << "\nrussianAgenda.txt\n";
        cout << "FullBeeMovie.mov\n";
        cout << "cat.png\n";
        cout << dirPath;
    }
    
    if(currentDir == "topsecretfiles"){
        if(gamePlayer->isSudoUserGET() != true){
            cout << "This directory can only be accessed by a sudo user....\nCome back once you hace unlocked this level of access\n";
        }else{
            cout << "reminder.txt\n";
            cout << "communistActivationFile3.rus\n";
        }
        cout << dirPath;
    }
    
    if(currentDir == "documents"){
        cout << "\nkungFuPandaMoviewScript.txt\n";
        cout << "newCookiesRecipe.pdf\n";
        cout << "acustudentgrades\n";
        cout << dirPath;
    }
    
    if(currentDir == "myhome"){ // !!!: this is not one of Schuberts Directories and should not be accessable from his macbook
        // TODO: migrate this function to a seperate class
        cout << "\nhackPhilSchubert.exe\n";
        cout << "internetExplorer.exe\n";
        cout << "ShoppingList.txt\n";
        string temp;
        temp =  gamePlayer->nameGET() + ":~ "+gamePlayer->nameGET()+"MacBook$ ";
        dirPathSET(temp);
        currentDirLocationSET("myhome");
        cout << dirPath;
    }
    
}

void CoreMechanics::beginTerminalLoop(string startingDir){
    // this is phil Schuberts Terminal loop
   // the current dir contents should already be displayed along with the path.
    //updateDirPath();// set the directory back to default
    // /\ this is obviously not a real terminal function but hey thats not the point

    
    if(startingDir == "myhome"){
        renderDirContents("myhome");
    }
    string input;
    
    while(true){
        getline(cin, input);
        stringstream inputStream(input);
        inputStream >> input;
        
        
        if(input == "cd"){
            if(inputStream >> input){
                if(isSupportedDir(input) and currentDirLocationGET() != "myhome"){
                    currentDirLocation = input;
                    updateDirPath();
                    dirStack.push(input);
                    cout << dirPath;
                } else{
                    cout << "please enter a valid directory\n";
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
            cout << "\n\nTerminal Commands:" << endl << "cd \'direectory name\' - navigates to specified directory\nls - lists the contents of current Dir\nrun - \'run exe files in terminal\'\nhelp - get a list of basic terminal commands and ones you have unlocked\nclear - clears the terminal screen\n";
            if(gamePlayer->hasCommand("read")){
                cout << "read <txt fileName> - This command allows you to read the contents of the specified .txt file\n";
            }if (gamePlayer->hasCommand("mission")) {
                cout << "mission - this command displays current story objective\n";
            }
            if(currentDirLocationGET() != "myhome")
                cout << "lsDirs - this will list out all the major directories that you can jump to\n";
            if (gamePlayer->hasCommand("inventory")) {
                cout << "inventory - this will display you current inventory\n";
            }
            if (gamePlayer->hasCommand("capture")) {
                cout << "capture <object> - this will capture any capturable object\n";
            }
            cout << dirPath;
        }
        else if(input == "read" and gamePlayer->hasCommand("read")){
            if(inputStream >> input){
                read(input);
                cout << dirPath;
            }
        }
        else if(input == "clear"){
            clearScreen();
            cout << dirPath;
        }
        else if(input == "run"){
            if(inputStream >> input){
                // ideally we would check to make sure this is a valid command befiore running it
                run(input);
            } else{
                cout << "To use run command, please enter the name of the .exe file\n you would like to run\n";
            }
            cout << dirPath;
        }
        else if(input == "mission" && gamePlayer->hasCommand("mission")){
            printObjective();
            cout << dirPath;
        }
        else if(input == "lsDirs"){
            renderMajorDirs();
            cout << dirPath;
        }
        else if(input == "inventory" and gamePlayer->hasCommand("inventory")){
            gamePlayer->renderInventory();
            cout << dirPath;
        }
        else if(input == "capture" and gamePlayer->hasCommand("capture")){
            
            if (inputStream >> input) {
                //TODO: add a checking system to make sure the object should be captureable
                gamePlayer->addToInventory(input);
                cout << "captured: " << input << endl;
            }
            
            cout << dirPath;
        }
        else{
            cout << dirPath;
        }
    }
    
    
}



void CoreMechanics::read(string filename)const{
    //TODO: make a textStorage class for all of this, call it whatever
    if(filename == "russianTransmission.txt"){
        string text = "\nMr.Shubert has no idea of our EVIL plan...\nwe should move forward with activation soon, just in time for wildcat week >:)\nas long as no one hacks into his computer and decypts our evil activation files (of which there are 3) and combines them to gain acces to our internal systems and shut down our evil plans forever then this missian is GOLDEN heh, man im so smart\n\nVlad's Diaries entry #21\n\n";
        printTextAnimation(text);
        if(gamePlayer->hasReadRussianTutorialGET() == false){
            prompEnterToContinue();
            clearScreen();
            printTextAnimation("OOOOOOOWEEEEEEEEEE\nJust as i expected, Phil Schubert IS a russian sleeper agent!");
            prompEnterToContinue();
            printTextAnimation("I cant let my boi willy get hurt like that, looks like im going to have to find those russian activation files\nand put an end to those commy schemes");
            prompEnterToContinue();
            
            clearScreen();
            gamePlayer->addUnlockedCommand("mission");
            gamePlayer->addUnlockedCommand("inventory");
            gamePlayer->addUnlockedCommand("capture");
            gamePlayer->hasReadRussianTutorialSET(true);
            
            printTextAnimation("you have unlocked the \'mission\', \'inventory\', and \'capture\' unix command\nmission will display your current game objective to progress the story\ncapture will allow you to transfer certain files to you computers inventory and store them for later\ninventory will display any file you have captured\n");
            prompEnterToContinue();
        }
    }
    else{
        cout << "unreadable......\n";
    }
}

void CoreMechanics::run(string exeName){
    if(exeName == "hackPhilSchubert.exe"){
        animationLoading(1, "Hacking Phil Schubert's MacBook");
        animationLoading(1, "Type \"help\" to get a list of commands you have or ones you've unlocked");
        dirPathSET("Schubert:~ philSchubertMacBook$ ");
        currentDirLocationSET("home");
        dirStack.push("home");
        updateDirPath();
    }else{ // add more if statments here to catch exe files that are there just for laughs and you want custom errors for, other wise the basic error will catch it.
        if(exeName == "internetExplorer.exe"){
            cout << "System Prompt: who the heck uses internet explorer, \n please run somthing, ANYTHNING better than internet explorer\n";
        }
        else
            cout << "No exe file named: \'" << exeName << "\'\n"; // Basic response
    }
}

void CoreMechanics::renderMajorDirs(){
    cout << endl;
    for (auto itr = majorDirs.begin(); itr < majorDirs.end(); itr++) {
        cout << *itr << endl;
    }
//    cout << endl;
}
