#include <iostream> 
#include <string>
#include "Floor.h"
#include "Game.h"
#include <fstream>
#include <cstdlib>

class Game;

using namespace std;

void printRaces(){
    cout << "please choose a race: "<< endl;
    cout << "s - shade" << endl <<"d - Drow" << endl << "v - vampire" << endl << "g - Goblin" << endl <<"t - Troll" << endl;
}

int main(int argc, char *argv[]){
    std::string fileName = "board.txt";

    if(argc == 2){
        fileName = argv[1];   // changing the fileName to the given argument 
    }
    int seed = 111;
    srand(seed);
    string playerRace;
    string input;

    printRaces();
    cin >> input;
//while loop 
    if(input != "s" && input != "d"  && input != "v"  && input != "g"  && input != "t" ){
          cout << "invalid player race selcted. Exiting.."<< endl; //not a valid player race selected
          return 0;
    }

    playerRace = input; //player race is selected properly

    Game *game = new Game(playerRace, fileName); 
    bool freezeEnemy = false;
    

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
            printRaces();
            cin >> input;
            if(input != "s" && input != "d"  && input != "v"  && input != "g"  && input != "t" ){
                cout << "invalid player race selcted. Exiting.."<< endl; //not a valid player race selected
                return 0;
            }
            playerRace = input;
            game = new Game(playerRace, fileName);
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
    
    //Floor *floor = new Floor(fileName);   //generating a new Floor
    //floor->printFloor();  //prints the generated floor 
}
