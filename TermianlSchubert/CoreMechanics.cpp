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
using std::cout;
using std::flush;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

//string directories[14];
////    string nakedPath;
//string dirPath;
//string commands[6];
//string currentDirLocation;
//int dirCount;
//User* gamePlayer;
//stack<string> dirStack;
//vector<string> captureableFiles;
//string objective;
//vector<string> majorDirs;
//bool finalSceneHappened;
//bool gameIsFinished;

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
    directories[7] = "myhome";
    directories[8] = "workFiles";
    directories[9] = "memeFolder";
    directories[10] = "chromePasswords";
    directories[11] = "movieScripts";
    directories[12] = "workFiles";
    directories[13] = "Россия";
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
        sleep_for(milliseconds(20));
        
    }
}

void CoreMechanics::printTextAnimation(int speed, const string& message) const{
    // Range loops are "for each" constructs; here: for each character in the string
    for (const char c: message)
    {
        // flush is used to make sure the buffer is emptied to the terminal immediately
        cout << c << flush;
        
        // Ask the thread to sleep for at least n millis.
        sleep_for(milliseconds(speed));
        
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
        sleep(1);
        std::cout << "\b\\" << std::flush;
        sleep(1);
        std::cout << "\b|" << std::flush;
        sleep(1);
        std::cout << "\b/" << std::flush;
        sleep(1);
        std::cout << "\b-" << std::flush;
    }
    clearScreen();
}
void CoreMechanics::animationLoading(int numberOfLoops, string passedText)const{
    clearScreen();
    std::cout << passedText << " -" << std::flush;
    for (int x = 0; x < numberOfLoops; x++) {
        sleep(1);
        std::cout << "\b\\" << std::flush;
        sleep(1);
        std::cout << "\b|" << std::flush;
        sleep(1);
        std::cout << "\b/" << std::flush;
        sleep(1);
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
    
    
    if(isSupportedDir(currentDir) != true and currentDirLocationGET() != "myhome" and currentDirLocationGET() != "Россия"){
        cout << "\n" << "-bash: cd: " << currentDir << " No such file or directory\n";
        cout << dirPathGET();
        return;
    }
    
    if(currentDir == "acustudentgrades"){
        if(gamePlayer->hasChangedGradesGET()){
            cout << "\nMac Demarco grades.grade\n";
            cout << "Bensons grades.grade\n";
            cout << gamePlayer->nameGET() + "'s grades.grade\n";
            cout << "Travis Towel's grades.grade\n";
            cout << "Jerry's grades.grade\n";
            cout << "cookie recipie.grade\n";
            cout << "Prather's Grades.grade\n";
            cout << dirPathGET();
        }
        else{
            gamePlayer->addUnlockedCommand("read");
            gamePlayer->hasChangedGradesSET(true);
            objectiveSET("Search around Mr.Schuberts MacBook for an signs of russian messages"); //TODO: grant the mission command ability way earlier
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
            cout << dirPathGET();
        }
    }
    
    if(currentDir == "home"){
        cout << "\nrussianTransmission.txt\n";// cant read this until read command is unlocked
        cout << "desktop\n";
        cout << "documents\n";
        cout << "topsecretfiles\n"; // this should require sudo access
        cout << "downloads\n";
        
        cout << dirPathGET();
    }
    
    if(currentDir == "desktop"){
        cout << "\nHollow Knight.app\n";
        cout << "memeFolder\n";
        cout << "HotSauceCollage.psd\n";
        cout << "dailynotes.txt\n"; //TRAVIS
        cout << "spotify.app\n";
        cout << "workFiles\n";
//        cout << "notes2.txt\n";
//        cout << "notes4.txt\n";
        cout << dirPathGET();
    }
    if(currentDir == "workFiles"){
        cout << "\nwork_agenda.txt\n"; //TRAVIS
        cout << "speech.txt"; //TRAVIS
        cout << "\nfunnyCats.png";
        cout << "\nchromePasswords";
        cout << "\nfantasyFootballLeague.excel";
        cout << "\nmovieScripts";
        cout << "\nwildcatLogo.psd";
        cout << "\norderMcdonalds.exe\n"; //TODO: add mcdonalds.exe to run function
 
        cout << dirPathGET();
    }
    if(currentDir == "memeFolder"){
        cout << "\ngarfieldMemes.png\n";
        cout << "deepFriedMemes,jpg\n";
        cout << "koreanMusic.mp3\n";
        cout << "russianMusic.mp3\n";
        cout << "communistActivationFile1.rus\n";
        
        cout << dirPathGET();
    }
    
    if(currentDir == "chromePasswords"){
        //TODO: add all of these to the read fucntion
        cout << "\ngarfieldMemes.png\n";
        cout << "acupassword.txt\n"; //TRAVIS
        cout << "dominosPassword.txt\n"; //TRAVIS
        cout << "googlePassword.txt\n"; //TRAVIS
        cout << "TerminalPassword.bat\n";
        cout << "spotifyPassword.txt\n"; //TRAVIS
        cout << dirPathGET();
    }
    
    if (currentDir == "movieScripts") {
        //TODO: add these to the read function
        cout << "\nlalaland.txt\n"; //TRAVIS
        cout << "shrek.txt\n"; //TRAVIS
        
        cout << dirPathGET();
    }
    
    
    if(currentDir == "downloads"){
        cout << "\nFullBeeMovie.mov\n";
        cout << "moreRamDownload.zip\n";
        cout << "cat.png\n";
        cout << "cat(2).png\n";
        cout << "cat(3).png\n";
        cout << "cat(4).png\n";
        cout << "cat(5).png\n";
        cout << "cat(6).png\n";
        cout << "communistActivationFile2.rus\n";
        cout << dirPathGET();
    }
    
    if(currentDir == "topsecretfiles"){
        if(gamePlayer->isSudoUserGET() != true){
            cout << "\nThis directory can only be accessed by a sudo user....\nCome back once you have captured the TerminalPassword.bat file and elevated access to sudo\n";
        }else{
            cout << "reminder.txt\n"; //TRAVIS
            cout << "communistActivationFile3.rus\n";
        }
        cout << dirPathGET();
    }
    
    if(currentDir == "documents"){
        cout << "\nkungFuPandaMoviewScript.txt\n"; //TRAVIS
        cout << "newCookiesRecipe.pdf\n";
        cout << "acustudentgrades\n";
        cout << dirPathGET();
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
        cout << dirPathGET();
    }
    
    if (currentDir == "Россия" and finalSceneHappenedGET()) {
        cout << "\nрабочий стол\n";
        cout << "тральщик.Фото\n";
        cout << "endCommySchemes.exe\n";
        cout << "путинский дневник боб\n";
        cout << "тральщик.приложение\n";
        cout << dirPathGET();
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
                if(isSupportedDir(input) and currentDirLocationGET() != "myhome" and currentDirLocationGET() != "Россия"){
                    
                    currentDirLocationSET(input);
                    updateDirPath();
                    dirStack.push(input);
                    cout << dirPathGET();
                } else{
                    if (currentDirLocationGET() == "Россия") {
                        cout << "ты не можешь сделать это здесь\n";
                        cout << dirPathGET();
                    }else{
                        cout << "please enter a valid directory\n";
                        cout << dirPathGET();
                    }
                    
                }
            }
            else{ // if nothing after "cd" or invalid
                cout << "please enter a valid directory\n";
                cout << dirPathGET();
            }
        }
        else if (input == "ls") {
//            cout << "DEBUG: EMPTY REQUEST";
            renderDirContents(currentDirLocationGET());
        }
        else if(input == "help"){
            cout << "\n\nTerminal Commands:" << endl << "cd \'direectory name\' - navigates to specified directory\nls - lists the contents of current Dir\nrun - \'run exe files in terminal\'\nhelp - get a list of basic terminal commands and ones you have unlocked\nclear - clears the terminal screen\nmission - this command displays current story objective\n";
            if(gamePlayer->hasCommand("read")){
                cout << "read <txt fileName> - This command allows you to read the contents of the specified .txt file\n";
            }
            if(currentDirLocationGET() != "myhome")
                cout << "lsDirs - this will list out all the major directories that you can jump to\n";
            if (gamePlayer->hasCommand("inventory")) {
                cout << "inventory - this will display you current inventory\n";
            }
            if (gamePlayer->hasCommand("capture")) {
                cout << "capture <object> - this will capture any capturable object (mostly intended for .bat and .rus files)\n";
            }
            cout << dirPathGET();
        }
        else if(input == "read" and gamePlayer->hasCommand("read")){
            if(inputStream >> input){
                read(input);
                cout << dirPathGET();
            }
        }
        else if(input == "clear"){
            clearScreen();
            cout << dirPathGET();
        }
        else if(input == "run"){
            if(inputStream >> input){
                // ideally we would check to make sure this is a valid command befiore running it
                run(input);
                if (gameIsFinishedGET()) {
                    break;
                }
            } else{
                cout << "To use run command, please enter the name of the .exe file\n you would like to run\n";
            }
            cout << dirPathGET();
        }
        else if(input == "mission"){
            printObjective();
            cout << dirPathGET();
        }
        else if(input == "lsDirs"){
            renderMajorDirs();
            cout << dirPathGET();
        }
        else if(input == "inventory" and gamePlayer->hasCommand("inventory")){
            gamePlayer->renderInventory();
            cout << dirPathGET();
        }
        else if(input == "capture" and gamePlayer->hasCommand("capture")){
            
            if (inputStream >> input) {
                if (input == "communistActivationFile1.rus" and (currentDirLocationGET() == "memeFolder") and (gamePlayer->isInInventory("communistActivationFile1.rus") == false)) {
                    gamePlayer->addToInventory(input);
                    gamePlayer->foundFilesCountSET((gamePlayer->foundFilesCountGET() + 1));
                    cout << "captured: " << input << endl;
                    if (gamePlayer->foundFilesCountGET() == 3) {
                        prompEnterToContinue();
                        startFinalScene();
                    }
                }else if (input == "communistActivationFile2.rus" and (currentDirLocationGET() == "downloads")and (gamePlayer->isInInventory("communistActivationFile2.rus")) == false) {
                    gamePlayer->addToInventory(input);
                    gamePlayer->foundFilesCountSET((gamePlayer->foundFilesCountGET() + 1));
                    cout << "captured: " << input << endl;
                    if (gamePlayer->foundFilesCountGET() == 3) {
                        prompEnterToContinue();
                        startFinalScene();
                    }
                }else if (input == "communistActivationFile3.rus" and (currentDirLocationGET() == "topsecretfiles") and (gamePlayer->isInInventory("communistActivationFile3.rus") == false)) {
                    gamePlayer->addToInventory(input);
                    gamePlayer->foundFilesCountSET((gamePlayer->foundFilesCountGET() + 1));
                    cout << "captured: " << input << endl;
                    if (gamePlayer->foundFilesCountGET() == 3) {
                        prompEnterToContinue();
                        startFinalScene();
                    }
                }else if (input == "TerminalPassword.bat" and (currentDirLocationGET() == "chromePasswords")and (gamePlayer->isInInventory("TerminalPassword.bat") == false)) {
                    gamePlayer->addToInventory(input);
                    cout << "captured: " << input << endl;
                    printTextAnimation("System: You have been granted sudo privillages.\n");
                    prompEnterToContinue();
                    gamePlayer->isSudoUserSET(true);
                }else{
                    cout << endl << input << " cannot be captured\n";
                }
                
            }
            
            cout << dirPathGET();
        }
        else{
            cout << dirPathGET();
        }
    }
    
    
}



void CoreMechanics::read(string filename){
    //TODO: make a textStorage class for all of this, call it whatever
    if(filename == "russianTransmission.txt"){
        objectiveSET("Find those darned commy activ ation file (communistActivationFile.rus), use the capture command to store them in your inventory");
        string text = "\nMr.Shubert has no idea of our EVIL plan...\nwe should move forward with activation soon, just in time for wildcat week >:)\n i cant wait to activate our sleeper agent Phil Schubert to BODY SLAM the school spirit out of willy the wildcat\nas long as no one hacks into his computer and decypts our evil activation files (of which there are 3) and combines them to gain acces to our internal systems and shut down our evil plans forever then this missian is GOLDEN heh, man im so smart\n\nVlad's Diaries entry #21\n\n";
        printTextAnimation(text);
        if(gamePlayer->hasReadRussianTutorialGET() == false){
            
            prompEnterToContinue();
            clearScreen();
            printTextAnimation("OOOOOOOWEEEEEEEEEE\nJust as i expected, Phil Schubert IS a russian sleeper agent!");
            prompEnterToContinue();
            printTextAnimation("I cant let my boi willy get hurt like that, looks like im going to have to find those russian activation files\nand put an end to those commy schemes");
            prompEnterToContinue();
            
            clearScreen();
//            gamePlayer->addUnlockedCommand("mission");
            gamePlayer->addUnlockedCommand("inventory");
            gamePlayer->addUnlockedCommand("capture");
            gamePlayer->hasReadRussianTutorialSET(true);
            
            printTextAnimation("you have unlocked the \'inventory\', and \'capture\' unix command\ncapture will allow you to transfer certain .bat and .rus files to you computers inventory and store them for later\ninventory will display any file you have captured\n");
            prompEnterToContinue();
        }
    }else{ //travis: add the contents of .txt files here before this last else statment
        cout << "unreadable......\n";
    }
}

void CoreMechanics::run(string exeName){
    if(exeName == "hackPhilSchubert.exe"){
        animationLoading(1, "Hacking Phil Schubert's MacBook... ");
        dirPathSET("Schubert:~ philSchubertMacBook$ ");
        currentDirLocationSET("home");
        dirStack.push("home");
        updateDirPath();
    }else if(exeName == "internetExplorer.exe"){
            cout << "System Prompt: who the heck uses internet explorer, \n please run somthing, ANYTHNING better than internet explorer\n";
    }else if(exeName == "hackTheRussians.exe" and finalSceneHappenedGET()){
        animationLoading(1, "загрузка ");
        animationLoading(1, "хорошо, это эпично ");
        animationLoading(1, "русский текст ");
        currentDirLocationSET("Россия");
        dirPathSET("Россия:~ компьютерпутина$ ");
    }else if(exeName == "endCommySchemes.exe" and finalSceneHappenedGET() and currentDirLocationGET() == "Россия"){
        clearScreen();
        animationLoading(1, "Мистер Старк, я не чувствую себя так хорошо... ");
        printTextAnimation(1, "Обычно, обе ваши задницы были бы мертвы, как ебаная жареная курица, но вам посчастливилось вытащить это дерьмо, пока я нахожусь в переходном периоде, поэтому я не хочу убивать вас, я хочу помочь вам. Но я не могу отдать тебе это дело, оно не принадлежит мне. Кроме того, я уже прошел через слишком много дерьма сегодня утром за это дело, чтобы передать его тебе.Ты видишь здесь Телепузиков? Ты видишь тонкую пластиковую бирку, прикрепленную к моей рубашке с моим именем? Вы видите маленького азиатского ребенка с пустым выражением лица, Сидящего снаружи на механическом вертолете, который трясется, когда вы кладете в него четвертаки? Нет? Ну, это то, что вы видите в магазине игрушек. И ты, наверное, думаешь, что ты в магазине игрушек, потому что ты здесь покупаешь ребенка по имени ДжебТвои кости не ломаются, мои ломаются. Это понятно. Ваши клетки реагируют на бактерии и вирусы иначе, чем мои. Ты не заболеешь, а я заболею. Это тоже совершенно очевидно. Но почему-то мы с тобой реагируем точно так же на воду. Мы глотаем слишком быстро, мы задыхаемся. Если что-то попадет в легкие, мы утонем. Как бы нереально это ни казалось, мы связаны, ты и я. мы находимся на одной кривой, только на противоположных концах.Обычно, обе ваши задницы были бы мертвы, как ебаная жареная курица, но вам посчастливилось вытащить это дерьмо, пока я нахожусь в переходном периоде, поэтому я не хочу убивать вас, я хочу помочь вам. Но я не могу отдать тебе это дело, оно не принадлежит мне. Кроме того, я уже прошел через слишком много дерьма сегодня утром за это дело, чтобы передать его тебеОбычно, обе ваши задницы были бы мертвы, как ебаная жареная курица, но вам посчастливилось вытащить это дерьмо, пока я нахожусь в переходном периоде, поэтому я не хочу убивать вас, я хочу помочь вам. Но я не могу отдать тебе это дело, оно не принадлежит мне. Кроме того, я уже прошел через слишком много дерьма сегодня утром за это дело, чтобы передать его тебе.Теперь, когда мы знаем, кто ты, я знаю, кто я. Я не ошибся! Все это имеет смысл! В комиксе ты знаешь, как определить, кто будет главным злодеем? Он полная противоположность герою. И чаще всего они друзья, как ты и я! Я должен был знать, когда именно... Ты знаешь почему, Дэвид? Из-за детей. Они называли меня Мистер Гласс.Твои кости не ломаются, мои ломаются. Это понятно. Ваши клетки реагируют на бактерии и вирусы иначе, чем мои. Ты не заболеешь, а я заболею. Это тоже совершенно очевидно. Но почему-то мы с тобой реагируем точно так же на воду. Мы глотаем слишком быстро, мы задыхаемся. Если что-то попадет в легкие, мы утонем. Как бы нереально это ни казалось, мы связаны, ты и я. мы находимся на одной кривой, только на противоположных концах.Ну, то, как они делают шоу, они делают одно шоу. Это шоу называется пилот. Затем они показывают это шоу людям, которые делают шоу, и на основании этого шоу они решают, будут ли они делать больше шоу. Некоторые пилоты выбираются и становятся телевизионными программами. Некоторые нет, становятся ничем. Она снялась в одной из тех, что стали ничем.Путь праведника окружен со всех сторон беззакония себялюбивые и тирания злых людей. Блажен тот, кто во имя милосердия и доброй воли, пастухи слабых через долину тьмы, ибо Он воистину страж брату своему и спаситель детей заблудших. И я обрушу на тебя великую месть и ярость на тех, кто попытается отравить и уничтожить моих братьев. И ты узнаешь, что меня зовут Господь, когда я возложу на тебя свою месть.Теперь, когда мы знаем, кто ты, я знаю, кто я. Я не ошибся! Все это имеет смысл! В комиксе ты знаешь, как определить, кто будет главным злодеем? Он полная противоположность герою. И чаще всего они друзья, как ты и я! Я должен был знать, когда именно... Ты знаешь почему, Дэвид? Из-за детей. Они называли меня Мистер Гласс.Теперь, когда есть Tec-9, дерьмовый пистолет-распылитель из?");
        gameIsFinishedSET(true);
    }else{
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

bool CoreMechanics::isCaptureReady(string file)const{
    bool answer = false;
    
    for (auto itr = captureableFiles.begin(); itr != captureableFiles.end(); itr++) {
        if (file == *itr) {
            answer = true;
        }
    }
    
    return answer;
}

void CoreMechanics::startFinalScene(){
    clearScreen();
    printTextAnimation("OOOOOOOOWEEEEEEE we got all the commy activation files.\n well looks like it makes up a larger .exe file, i'll run it through the good ol' decypter thing or whatever.\n");
    prompEnterToContinue();
    animationLoading(2, "decrypting russian files ");
    printTextAnimation("hackTheRussians.exe has been added to your inventory!");
    prompEnterToContinue();
    finalSceneHappenedSET(true);
    gamePlayer->addToInventory("hackTheRussians.exe");
}
