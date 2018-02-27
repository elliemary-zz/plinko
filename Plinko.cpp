/****************************
 * Ellie Mary Finley
 * 
 * Plinko Game Sim
 ***************************/


#include <iostream>
#include <stdlib.h> //includes rand
#include <ctime> //includes time - used to seed rand


//Debug
//#define USEDEBUG //Uncomment this line to see plinko details

#ifdef USEDEBUG
#define Debug( x ) std::cout << x
#else
#define Debug( x ) 
#endif


using namespace std;



class Game
{
private:
    int value;
    float X;
    int Y;
    void Move();
    
public:
    Game();
    void Drop();
};

Game::Game()
{
    // Initialize Random Seed
    srand (time(NULL));
    
    // Initialize Values
    value = -1;
    X = 0;
    Y = 0;
}

void Game::Drop()
{
    // Reset Values
    value = -1;
    X = 0;
    Y = 0;
    
    // Randomly pick start location of disk
    int start = rand()%8 + 1;
    
    // Modify disk location based on random start position
    Debug("The disk will be dropped at start position #" << start << endl);
    X = start - 0.5;
    Y = 2;
    Debug("The first peg/wall the disk hits is at position: (" << X << "," << Y << ")" << endl);
    
    // Keep falling until it reaches the bottom
    while(Y < 7)
    {
        Move();
    }
    
    if(X==1 || X==7)
        value = 250;
    else if(X==2 || X==6)
        value = 500;
    else if(X==3 || X==5)
        value = 0;
    else if(X == 4)
        value = 2000;

    cout << "The disk fell into a bucket with value: " << value << endl;
}

void Game::Move()
{
    int up_or_down = -1;;
    Y++;
    
    // If it hits a wall, bounce opposite direction
    if(X==0.5)
        X=1;
    else if(X==7.5)
        X=7;
        
    // Otherwise, randomly go left or right
    else{
        up_or_down = rand()%2;
        X = X + up_or_down - 0.5;
    }
    
    Debug("The disk hits at: (" << X <<" , " << Y << ")" << endl); 
}
 
int main() {

    Game game;
    
    for(int x = 0; x < 4; x++)
    {
        game.Drop();
    }
    
    return 0;
}