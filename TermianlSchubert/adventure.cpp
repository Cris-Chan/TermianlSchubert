//
//  main.cpp
//  TermianlSchubert
//
//  Created by Cristian villanueva on 10/25/18.
//  Copyright © 2018 Cristian villanueva. All rights reserved.
//

#include <iostream>
#include "Story.h"
#include "CoreMechanics.h"
#include "User.h"
#include "SpoofedTerminalObject.h"
using namespace std;
int main() {
    Story mainStory;
    User hero;
    CoreMechanics core;
    string tempString;
    
//    cout << "Starting...\n";
    core.clearScreen();
    core.printTextAnimation("Oh shoot! im failing bible!");
    core.prompEnterToContinue();
    core.printTextAnimation("Well i guess im left with the usual 2 options...\n");
    core.printTextAnimation("<drop out of college> OR <Hack into Phil Schuberts MacBook and change my grade>\n");
    
    string response = core.getChoice();
    
    if(response.find("drop") != std::string::npos){
        core.clearScreen();
        core.printTextAnimation("You have dropped out of college!\n The End\n");
        return 0;
    }
    // type anthing else out and you decide to hack schubert lol (this will change in the future)
    
    core.clearScreen();
    core.printTextAnimation("*you whisper to yourself* \"Forgive me Mr.Schubert.... but I must go all out just this once\" \n");
    core.prompEnterToContinue();
    core.printTextAnimation("*You pull out your laptop* \n SYSTEM PROMPT: \" Please Enter your password (Hint, its your Name)\":  ");
    getline(cin, tempString);
//    hero.userNameSET(tempString);
    hero.nameSET(tempString);
    
    core.animationLoading(2);
    
    // THIS CONCLUDES THE INTRO OF THE GAME (note: this is a rough version)
    // from here on most of the game is within the fake terminal shell (most likely will make a new obejct for this instead of making "core" object handle it)
    
    core.renderDirContents("home");
    core.beginTerminalLoop("home");
    
    
    
}
