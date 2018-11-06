#include <iostream>
#include <vector>
using namespace std;

class Story{ // will be made in the future to only have one instance ever
private:
    int progression;
    bool reachedEnd;
    
public:
    Story(){
        progression = 0;
        reachedEnd = false;
    }
    
    //GETTERS
    int progressionGET(){return progression;}
    bool reachedEndGET(){return reachedEnd;}
    
    //SETTERS
    void progressionSET(int value){progression = value;}
    void reachedEndSET(bool value){reachedEnd = value;}
};
