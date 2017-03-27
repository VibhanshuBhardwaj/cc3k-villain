#include <iostream> 
#include <string>
#include "Floor.h"
#include "Game.h"
#include <fstream>
#include <cstdlib>

class Game;

using namespace std;

string getPlayerRace(){
    cout << "please choose a race: "<< endl;
    cout << "s - Shade" << endl <<"d - Drow" << endl << "v - Vampire" << endl << "g - Goblin" << endl <<"t - Troll" << endl;
    string input;
    cin >> input;
    if(input == "q"){
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

    if(argc == 2){
        fileName = argv[1];   // changing the fileName to the given argument 
    }
    int seed = 111;
    srand(seed);
    string playerRace;
    playerRace = getPlayerRace();
    if(playerRace == "q"){
        cout << "Game quit..." <<endl;
        return 0;
    }
    Game *game = new Game(playerRace, fileName); 
    game->printGame();
    bool freezeEnemy = false;
    string input;

    while(game->isAlive()){
        cin >>input;

        if(cin.fail()){
            delete game;
            break;
        }
        //check if health is 0 or won
        else if(input == "q"){
            delete game;
            cout << "Game quit..." <<endl;
            return 0;
        }
        else if(input == "p"){game->printGame();}
        else if(input == "r"){
            delete game;
            playerRace = getPlayerRace();
            if(playerRace == "q"){
                cout << "Game quit..." <<endl;
                return 0;
            }
            game = new Game(playerRace, fileName);
            game->printGame();
            freezeEnemy = false;
        }
        else if(input == "u"){ //use Potion
            string potionDir; //potion direction 
            cin >> potionDir;
            //game->usePotion(potionDir);
        }
        else if(input == "a"){ //attack 
            string atkDir;
            cin >> atkDir;
            //game->atkDirection(atkDir);
        }
        else if(input == "f"){ //freeze enemy
            if(freezeEnemy){
                freezeEnemy = false;
                //game->unFreezeEnemy();
            }
            else{ //freezeenemy is false
                freezeEnemy = true;
                //game->freezeEnemy();
            }
        }
        //cout << input <<endl;
        //else if((input == "no") || (input == "so") || (input == "we") || (input == "ea") || (input == "nw") || (input == "ne") || (input == "se") || (input = "sw")){
            //valid direction
            //game->playerMove(input);
        //}
        //if(game->isWon()){ //to check if the game is won. Runs after every user input.
        //    cout << "Congratulations you've won the Game!!"<< endl<< "Well Played!!" << endl;
        //    delete game;
        //    break;
        //}
      
        else{
            //invalid input
            cout << "Invalid input. Please enter a valid input"<<endl;
        }
    }
    delete game;
}
