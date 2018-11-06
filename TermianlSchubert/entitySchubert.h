#include <iostream>
#include "gameEntity.h"

class entitySchubert : gameEntity{
private:
    int health;
public:
    entitySchubert() : gameEntity("schubert"){
        health = 10;
    }
    
    int healthGET(){return health;}
    
    void healthSET(int input){health = input;}
};
