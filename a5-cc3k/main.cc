#include <iostream>
#include <string>
#include "Floor.h"
#include "Game.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <climits>
#include <limits>
class Game;

using namespace std;

string getPlayerRace(){
    cout << "please choose a race: "<< endl;
    cout << "s - Shade" << endl <<"d - Drow" << endl << "v - Vampire" << endl << "g - Goblin" << endl <<"t - Troll" << endl;
    string input;
    cin >> input;
    if(input == "q" || cin.eof()){
        return "q";
    }
    else if(input != "s" && input != "d"  && input != "v"  && input != "g"  && input != "t" ){
        cout << "invalid player race selcted. "<< endl; //not a valid player race selected
        getPlayerRace();
    }
    return input;
}


int main(int argc, char *argv[]){
    std::string fileName = "board.txt";
    int seed = 12390;
    if(argc >= 2){
        fileName = argv[1];   // changing the fileName to the given argument

        if(argc == 3){
            istringstream ss(argv[2]);
            ss >> seed;
        }
    }
    //srand(seed);
    srand(time(NULL));
    string playerRace;
    playerRace = getPlayerRace();
    if(playerRace == "q"){
        cout << "Game quit..." <<endl;
        return 0;
    }
    bool isDlcEnabled = false;
    string dlc;
    cout << "Enter Y/N to enable/disable DLCs. " << endl;
    cin >> dlc;;
    if (dlc == "y" || dlc == "Y") {
        isDlcEnabled = true;
    }
    else if (dlc == "y-makeMeRut" || dlc == "Y-makeMeRut") {
        cout << "making rut" << endl;
        isDlcEnabled = true;
        playerRace = "r";
    }
    else if (dlc == "n" || dlc == "N") {
        isDlcEnabled = false;
    }
    Game *game = new Game(playerRace, fileName);

    if (isDlcEnabled) cout << "DLC enabled! " << endl;
    else cout << "DLC disabled! " << endl;
    bool freezeEnemy = false;

  //  game->printGame(); //to print after user's DLC choice
    string input;

    while(game->isAlive()){
        cin >>input;
        if(cin.fail() || cin.eof()){
            cout << "Game quit... " << endl;;
           // delete game;
            break;
        }
        //check if health is 0 or won
      //  cout << "cin eof" << cin.eof() << endl;
        if(input == "q" ){
            delete game;
            cout << "Game quit..." <<endl;
            return 0;
        }
        else if(input == "p"){
            game->printGame();
        }
        else if(input == "r"){
            delete game;
            playerRace = getPlayerRace();
            if(playerRace == "q"){
                cout << "Game quit..." <<endl;
                return 0;
            }
            game = new Game(playerRace, fileName);
            freezeEnemy = false;
        }
        //else if (input == "rhealthmax"){
        //    game->restoreHealth();
        //}
        else if(input == "u"){ //use Potion
            string potionDir; //potion direction
            cin >> potionDir;
            game->usePotion(potionDir);
        }
        else if(input == "a"){ //attack
            string atkDir;
            cin >> atkDir;
            //cout << "calling game->atkDirection with " << atkDir << endl;
            game->atkDirection(atkDir);
        }
        else if(input == "f"){ //freeze enemy
            if(freezeEnemy){
                freezeEnemy = false;
                game->unFreezeEnemy();
            }
            else{ //freezeenemy is false
                freezeEnemy = true;
                game->freezeEnemy();
            }
        }

        else if((input == "no") || (input == "so") || (input == "we") || (input == "ea") || (input == "nw") || (input == "ne") || (input == "se") || (input == "sw")){
            game->playerMove(input);
            if(game->isWon()){ //to check if the game is won. Runs after every user input.
                break;
            }
        }

        else if (isDlcEnabled && (input == "maxHealth" ||input == "maxhealth")){
            int maxInt = numeric_limits<int>::max();
            game->setPlayerHp(maxInt);
            game->setPlayerAction(game->getPlayerAction() + "Set health to maximum possible value! ");
            game->printGame();
        }
        else if (isDlcEnabled && (input == "boostAttack" ||input == "boostattack")){
            game->boostPlayerAtk(20);
            game->setPlayerAction(game->getPlayerAction() + "Boosted attack by 20 points! ");
            game->printGame();
        }
        else if (isDlcEnabled && (input == "boostDefence" ||input == "boostdefence")){
            game->boostPlayerDef(15);
            game->setPlayerAction(game->getPlayerAction() + "Boosted defence by 15 points! ");
            game->printGame();
        }
        else{
            //invalid input
            cout << "Invalid input. Please enter a valid input"<<endl;
        }
    }
    if (!game->isAlive()) cout << "Player died! Game over." << endl;
    delete game;
}

