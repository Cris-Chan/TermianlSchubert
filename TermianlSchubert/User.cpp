//
//  User.cpp
//  TermianlSchubert
//
//  Created by Cristian villanueva on 11/6/18.
//  Copyright © 2018 Cristian villanueva. All rights reserved.
//

#include "User.h"

bool User::hasCommand(string command)const{
    bool answer = false;
    
    for(auto it = unlockedCommands.begin(); it != unlockedCommands.end(); it++){
        if(*it == command)
            answer = true;
    }
    
    return answer;
}

bool User::isInInventory(string value)const{
    bool answer = false;
    
    for(auto itr = inventory.begin(); itr < inventory.begin(); itr++){
        if(value == *itr)
            answer = true;
    }
    
    return answer;
}

void User::renderInventory()const{
    cout << endl << "INVENTORY(" << inventory.size() << ")" << endl << "---------------------";
    for(auto itr = inventory.begin(); itr != inventory.end(); itr++){
        cout << "\n[" << *itr << "]";
    }
    cout << endl << endl;
}
